// TrafficLight.js
import React, { useState, useEffect, useCallback } from "react";
import { View, Text, TouchableOpacity, StyleSheet } from "react-native";
import Draggable from "react-native-draggable";
import axios from "axios";

const TrafficLight = ({ id, onClose }) => {
  const [currentLight, setCurrentLight] = useState(null);

  const [lightStyles, setLightStyles] = useState({
    red: "gray", // Default off state
    orange: "gray",
    green: "gray",
  });

  const setColorsBasedOnLight = useCallback((newCurrentLight) => {
    setLightStyles({
      red: newCurrentLight === "red" ? "red" : "gray",
      orange: newCurrentLight === "orange" ? "orange" : "gray",
      green: newCurrentLight === "green" ? "green" : "gray",
    });
    setCurrentLight(newCurrentLight);
  }, []);

  const fetchData = async () => {
    try {
      const response = await axios.get(
        `http://192.168.201.254:5000/traffic/${id}`
      );
      const newCurrentLight = response.data.color;
      if (newCurrentLight) {
        setColorsBasedOnLight(newCurrentLight);
      } else {
        console.error("Invalid response format:", response.data);
      }
    } catch (error) {
      console.error("Error fetching current light data:", error.message);
    }
  };

  const handleColorChange = async (color) => {
    try {
      await axios.post(
        `http://192.168.201.254:5000/api/change-sequence-${color}`
      );
      setColorsBasedOnLight(color); // Immediately update the state
    } catch (error) {
      console.error("Error changing sequence:", error.message);
    }
  };

  useEffect(() => {
    fetchData();

    const intervalId = setInterval(fetchData, 500);

    return () => clearInterval(intervalId);
  }, [setColorsBasedOnLight]);

  return (
    <Draggable x={-7} y={-30}>
      <View style={styles.content}>
        <TouchableOpacity onPress={onClose} style={styles.closeButton}>
          <Text style={styles.closeButtonText}>X</Text>
        </TouchableOpacity>
        <View
          style={[styles.square, { backgroundColor: lightStyles.red }]}
          onTouchEnd={() => handleColorChange("red")}
        ></View>
        <View
          style={[styles.square, { backgroundColor: lightStyles.orange }]}
          onTouchEnd={() => handleColorChange("orange")}
        ></View>
        <View
          style={[styles.square, { backgroundColor: lightStyles.green }]}
          onTouchEnd={() => handleColorChange("green")}
        ></View>
        {currentLight ? (
          <Text style={styles.lightText}>Current Light: {currentLight}</Text>
        ) : (
          <Text>Waiting.....</Text>
        )}
      </View>
    </Draggable>
  );
};

const styles = StyleSheet.create({
  content: {
    position: "absolute",
    top: "-30%",
    left: "-7%",
  },
  closeButton: {
    position: "absolute",
    top: 0,
    right: 0,
    padding: 3,
  },
  closeButtonText: {
    fontSize: 18,
    fontWeight: "bold",
    color: "black",
  },
  square: {
    width: 100,
    height: 100,
    borderWidth: 3,
    borderColor: "#555",
    borderRadius: 100,
    marginTop: 10,
  },
  lightText: {
    marginTop: 10,
    fontSize: 16,
  },
});

export default TrafficLight;
