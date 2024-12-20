from functools import cmp_to_key

from .llf import TaskType, TaskIns, priority_cmp
from math import gcd
from functools import reduce


def _lcm(a, b):
    return abs(a * b) // gcd(a, b) if a and b else 0


def lcm(a):
    return reduce(_lcm, a)


# input_tasks = [
#     {"Task": 1, "Arrival Time": 0, "Burst Time": 3, "Deadline": 7, "Period": 20},
#     {"Task": 2, "Arrival Time": 0, "Burst Time": 2, "Deadline": 4, "Period": 5},
#     {"Task": 3, "Arrival Time": 0, "Burst Time": 2, "Deadline": 9, "Period": 10}
# ]


def llf_function(input_tasks):
    task_types = []
    tasks = []
    hyperperiod = []
    gantt = []

    for input_task in input_tasks:
        task_types.append(TaskType(
            period=input_task["Period"],
            release=input_task["Arrival Time"],
            execution=input_task["Burst Time"],
            deadline=input_task["Deadline"],
            name=input_task["Task"]
        ))
    # Calculate hyperperiod
    for task_type in task_types:
        hyperperiod.append(int(task_type.period))
    hyperperiod = lcm(hyperperiod)

    # Sort types rate monotonic
    task_types = sorted(task_types, key=cmp_to_key(TaskType.tasktype_cmp))

    # Create task instances
    for i in range(0, hyperperiod):
        for task_type in task_types:
            if (i - task_type.release) % task_type.period == 0 and i >= task_type.release:
                start = i
                end = start + task_type.execution
                priority = start + task_type.deadline - task_type.execution
                tasks.append(TaskIns(start=start, end=end, priority=priority, name=task_type.name))

    # Check utilization
    utilization = 0
    for task_type in task_types:
        utilization += float(task_type.execution) / float(task_type.period)
    if utilization > 1:
        print('Utilization error!')

    # Simulate clock
    clock_step = 1
    for i in range(0, hyperperiod, clock_step):
        # Fetch possible tasks that can use cpu and sort by priority
        possible = []
        for t in tasks:
            if t.start <= i:
                possible.append(t)
        possible = sorted(possible, key=cmp_to_key(priority_cmp))

        # Select task with the highest priority
        if len(possible) > 0:
            on_cpu = possible[0]
            print(on_cpu.get_unique_name(), " uses the processor. ", end=' ')
            gantt.append((on_cpu.name, clock_step))
            on_cpu.priority += 1
            if on_cpu.use(clock_step):
                tasks.remove(on_cpu)
                print("Finish!", end=' ')
        else:
            print('No task uses the processor. ')
            gantt.append(('No Task', clock_step))
        print("\n")

    # Print remaining periodic tasks
    for p in tasks:
        print(p.get_unique_name() + " is dropped due to overload at time: " + str(i))

    #print("Gantt chart:", gantt)
    return utilization, gantt
#llf_runner(input_tasks)