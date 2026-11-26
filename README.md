# Logistic Regression from Scratch (C)

A small educational project implementing Logistic Regression from scratch in C as part of my studies in Machine Learning.

The project focuses on understanding the underlying mathematics and implementing the learning process without relying on machine learning libraries.

## Features

- Logistic Regression implementation in C.
- Sigmoid activation function.
- Binary Cross-Entropy loss.
- Gradient Descent optimization.
- Configurable learning rate and model parameters.
- Training and prediction modes.
- Model parameter persistence.

## Project Structure

```text
ML1/
├── src/
│   ├── main.c
│   ├── model.c
│   └── parser.c
├── lib/
│   ├── model.h
│   └── parser.h
├── config.txt
├── data.txt
└── CMakeLists.txt
```

## Requirements

- C compiler supporting C17.
- CMake.

## Usage

### 1. Build

```bash
cmake -S . -B build
cmake --build build
```

### 2. Train the model

```bash
./build/model -learn 1000
```

Replace `1000` with the desired number of training epochs.

### 3. Make predictions

```bash
./build/model -predict
```

## Configuration

The model parameters are stored in `config.txt`:

```text
w = 0
b = 0
L = 0.1
```

Where:

- `w` — weight.
- `b` — bias.
- `L` — learning rate.

## Dataset

The dataset is stored in `data.txt` and follows this format:

```text
n
x1, y1
x2, y2
...
xn, yn
```

The first line specifies the number of samples. Each subsequent line contains an input value and its corresponding binary label.

## Motivation

This project was created to explore the mathematical foundations of Logistic Regression and understand how a machine learning model learns from data through gradient descent.

It is a learning project, so there is still room for improvement.
