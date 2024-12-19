
---

# 🚦 **Connected Red Light IoT System** 🚦

This project demonstrates a **Connected Red Light** IoT system where a red light is controlled remotely via a **mobile application**. It uses **React.js** for the frontend, **Node.js** for the backend, and **ESP8266** for IoT control. The system allows users to interact with the red light and schedule its on/off times.

---

## 📋 Table of Contents

1. [Connected Red Light IoT System](#connected-red-light-iot-system)
   - [Technologies Used](#technologies-used)
   - [Architecture](#architecture)
   - [Installation](#installation)
   - [Usage](#usage)
   - [Screenshots](#screenshots)
2. [Scheduling Algorithms Simulation](#scheduling-algorithms-simulation)
   - [Technologies Used](#technologies-used-1)
   - [Installation](#installation-1)
   - [Usage](#usage-1)
   - [Screenshots](#screenshots-1)
3. [Charger Simulation with Non-Linear Regulator in Proteus](#charger-simulation-with-non-linear-regulator-in-proteus)
   - [Technologies Used](#technologies-used-2)
   - [Installation](#installation-2)
   - [Usage](#usage-2)
   - [Screenshots](#screenshots-2)
4. [Teamwork](#teamwork)

---

## 🚦 **Connected Red Light IoT System** 🚦

### 🛠️ **Technologies Used**

- **Frontend (Mobile App)**: 
  - 🖥️ **React.js**
- **Backend**: 
  - 🌐 **Node.js**
- **IoT Device**: 
  - 💡 **ESP8266** (for controlling the red light)
- **Database**: 
  - 🗄️ **MongoDB**
  
---

### 🏗️ **Architecture**

```plaintext
Mobile App (React.js) ↔ Backend (Node.js) ↔ IoT Device (ESP8266)
                                    ↔ MongoDB (Database)
```

---

### ⚙️ **Installation**

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/connected-red-light-iot.git
   cd connected-red-light-iot
   ```

2. **Backend Setup**:
   ```bash
   cd backend
   npm install
   npm start
   ```

3. **Frontend Setup**:
   ```bash
   cd mobile
   npm install
   npm start
   ```

4. **IoT Device Setup (ESP8266)**:
   - Flash firmware and connect to the **Node.js** server.
   - Monitor via mobile app.

---

### 📱 **Usage**

1. Open the **Mobile App**.
2. Control the **Red Light** on/off.
3. **Schedule** the light’s operation using a real-time clock.

---

### 📸 **Screenshots**

- **Red Light Control Interface:**
  ![Mobile App](https://via.placeholder.com/500x300?text=Red+Light+Control)

---

---

## 📅 **Scheduling Algorithms Simulation** 🧠

This project simulates **scheduling algorithms** in real time. It allows users to visualize and interact with various scheduling strategies like **FCFS**, **SJF**, **EDF**, **RM**, **DM**, **LLM**, and more. The system is built using **Django**, **Flask**, and **Streamlit** for different scheduling use cases.

---

## 🛠️ **Technologies Used**

- **Backend**: 
  - 🐍 **Django** (for scheduling algorithm logic)
  - 🔥 **Flask** (for real-time task management)
- **Visualization**: 
  - 📊 **Streamlit** (for interactive dashboard)
- **Algorithms**: 
  - 🧠 **FCFS**, **SJF**, **EDF**, **RM**, **DM**, **LLM**

---

### ⚙️ **Installation**

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/scheduling-algorithms-simulation.git
   cd scheduling-algorithms-simulation
   ```

2. **Backend Setup (Django)**:
   ```bash
   cd django
   pip install -r requirements.txt
   python manage.py runserver
   ```

3. **Backend Setup (Flask)**:
   ```bash
   cd flask
   pip install -r requirements.txt
   python app.py
   ```

4. **Run Streamlit for Visualization**:
   ```bash
   cd streamlit
   streamlit run dashboard.py
   ```

---

### 📊 **Usage**

1. Use the **Django** or **Flask** app to input tasks and run scheduling algorithms.
2. **Streamlit** will visualize the results and allow interaction with the algorithms' behavior.

---

### 📸 **Screenshots**

- **Scheduling Algorithm Dashboard:**
  ![Scheduling Visualization](https://via.placeholder.com/500x300?text=Scheduling+Visualization)

---

## ⚡ **Charger Simulation with Non-Linear Regulator in Proteus** 🔋

This project demonstrates the simulation of a **charger circuit** using a **non-linear regulator** in **Proteus**. The simulation includes various components like **transistors**, **capacitors**, and **resistors**, and it simulates the behavior of a charger connected to a **battery**.

---

### 🛠️ **Technologies Used**

- **Simulation Software**: 
  - 🧑‍🔬 **Proteus**
- **Components**: 
  - 🔌 **Non-Linear Regulator**
  - 🏋️‍♀️ **Resistors, Capacitors, Transistors**
- **System**: 
  - ⚡ **Battery Charging System Simulation**

---

### ⚙️ **Installation**

1. **Download Proteus**:
   - [Proteus Download Link](https://www.labcenter.com/download/)

2. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/charger-simulation-proteus.git
   cd charger-simulation-proteus
   ```

3. **Proteus Setup**:
   - Open the `Charger_Simulation_Design.pdsprj` file in **Proteus**.
   - Run the simulation.

---

### 🔋 **Usage**

1. Open **Proteus** and load the project.
2. Start the simulation to visualize how the non-linear regulator charges the battery.
3. Adjust parameters like voltage and current to see real-time effects.

---

### 📸 **Screenshots**

- **Charger Simulation in Proteus:**
  ![Charger Simulation](https://via.placeholder.com/500x300?text=Charger+Simulation)

---

## 🎥 **Demonstration Video**

For a demonstration of the three projects, check out the video below:

📹 [Watch Demo](https://youtube.com/your-demo-link)

---

## 🚀 **Future Enhancements**

- **Connected Red Light IoT System**:
  - Voice control with **Alexa** or **Google Assistant**.
  - Add more scheduling features like **randomized intervals**.

- **Scheduling Algorithms Simulation**:
  - Implement more advanced scheduling strategies.
  - Add real-time scheduling with adjustable task durations.

- **Charger Simulation**:
  - Improve simulation accuracy by adding temperature effects.
  - Simulate different battery types and charging cycles.

---

## 🤝 **Teamwork**

This project was carried out by the following team members:

- **Chouaib Kouraichi**
- **Saad Nahi**
- **Wissal Ouichou**
- **Aicha Oukdour**

---

## 🤝 **Contributing**

Contributions are welcome! Feel free to fork the repository, create new branches, and make pull requests.

---

## 📄 **License**

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

---
