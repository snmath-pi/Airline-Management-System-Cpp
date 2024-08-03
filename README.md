# Airline Management System

A basic airline management system created using C++ and MySQL. This project demonstrates how to interact with a MySQL database to manage flight reservations.

## Features

- Connects to a MySQL database.
- Allows users to book flights if seats are available.
- Automatically updates the number of available seats in the database.

## Database

The database contains a table named `Airline` with the following columns:

- `FlightNumber`: The unique identifier for each flight.
- `Dep`: Departure location.
- `Des`: Destination location.
- `Seats`: Number of available seats.

## Requirements

- MySQL
- C++ compiler (e.g., g++)
- MySQL Connector/C++ (for MySQL interaction)

## Setup

1. **Install MySQL**: Download and install MySQL from [here](https://dev.mysql.com/downloads/mysql/).
2. **Set up the database**:
    ```sql
    CREATE DATABASE temp;
    USE temp;
    CREATE TABLE Airline (
        FlightNumber VARCHAR(10) PRIMARY KEY,
        Dep VARCHAR(50),
        Des VARCHAR(50),
        Seats INT
    );
    ```
3. **Install MySQL Connector/C++**: Follow the instructions [here](https://dev.mysql.com/downloads/connector/cpp/).

## Configuration

Update the database connection details in the C++ code:

```cpp
const char *HOST = "localhost";
const char *USER = "root";
const char *PW = "password123";
const char *DB = "temp";
