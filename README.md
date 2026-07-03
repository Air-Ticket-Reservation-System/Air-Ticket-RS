# Air-Ticket-RS

✈️ **Air Ticket Reservation System**

A full-stack Air Ticket Reservation System built with a vanilla HTML/CSS/JavaScript frontend, a Node.js + Express backend, and MySQL as the database. The system supports both customers and admins, letting customers search and book flights end-to-end while admins manage flights, aircraft, and airports through a dedicated dashboard.

## ✨ Features

- 🔐 Customer sign up & login
- 🔎 Search flights by origin, destination, and date
- 🪑 Interactive seat selection
- 🧳 Baggage add-on selection with fee calculation
- 💳 Multi-step booking wizard (passenger → seat → baggage → payment)
- 📋 View and manage personal bookings
- 🛫 Admin flight management (create, view, update)
- ✈️ Admin aircraft management
- 🏢 Admin airport management
- 🧾 Admin manifest / passenger list per flight
- 📊 Live dashboard stats (flights, passengers, aircraft, revenue)
- 🖥️ Built-in SQL playground with schema tree view and query terminal
- 📜 Query log panel for transparency into backend operations

## 🛠️ Technologies Used

- HTML5, CSS3, JavaScript (Vanilla)
- Node.js
- Express.js
- MySQL
- mysql2 (MySQL driver for Node.js)
- dotenv

## 📦 Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Air-Ticket-Reservation-System/Air-Ticket-RS
   cd air-ticket-reservation-system
   ```

2. **Install the required packages:**
   ```bash
   npm install
   ```

3. **Create the MySQL database and import the schema:**
   ```bash
   CREATE DATABASE ars
   mysql -u root -p ars < schema.sql
   ```

4. **Configure your environment variables:**
   
   Copy `.env.example` to `.env` and update your MySQL credentials:
   ```env
   DB_HOST=localhost
   DB_PORT=3306
   DB_USER=root
   DB_PASSWORD=
   DB_DATABASE=air_ticket_db
   PORT=3000
   ```

5. **Run the application:**
   ```bash
   npm start
   ```

6. **Open your browser and navigate to:**
   ```
   http://localhost:3000
   ```

## 📸 User Interface

The application provides a modern dark-themed graphical interface with:

- Customer authentication (login & sign up)
- Flight search and booking wizard
- Customer bookings dashboard
- Admin flight, aircraft, and airport management
- Admin manifest and statistics dashboard
- Built-in SQL playground for schema exploration and query testing

## 📌 Future Improvements

- Role-based route protection (JWT authentication)
- Online payment gateway integration
- E-ticket generation as PDF
- Email/SMS booking confirmations
- Flight status tracking & delay notifications
- Multi-city and round-trip booking support
- Fare comparison and dynamic pricing

## 👨‍💻 Author

**Muhammad Ehtisham**
- Department of Artificial Intelligence
- University of Sargodha

## 📄 License

This project was developed for educational purposes and academic learning.

---

**Project Explanation Video:** [Watch here](https://drive.google.com/file/d/1ZrbXCyl5low1ET2mue-f0ukwWugcj78_/view?usp=sharing)
