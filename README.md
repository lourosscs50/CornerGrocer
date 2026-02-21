📌 Corner Grocer – Grocery Purchase Analyzer

A robust, menu-driven C++ console application that analyzes grocery purchase data from a text file, calculates item purchase frequencies, generates structured output reports, and provides interactive lookup and visualization through a console interface.

The program processes transaction data to help identify purchasing trends and demonstrates practical use of file handling, data structures, and modular program design.

⸻

🚀 Overview

Corner Grocer reads grocery purchase records from an input file, analyzes item occurrences, and allows users to interact with the data through a structured menu system.

The application emphasizes maintainability, readability, and scalable program structure by separating logic into independent functions and applying consistent formatting practices.

⸻

✨ Features
	•	Menu-driven console interface
	•	File input/output processing
	•	Item frequency analysis
	•	Case-insensitive data normalization
	•	Interactive item search
	•	Histogram-style console visualization
	•	Structured output file generation
	•	Error handling and input validation
	•	Modular and maintainable program design

⸻

🧱 Tech Stack
	•	Language: C++
	•	Standard Library Components:
	•	std::map (associative container)
	•	File streams (ifstream, ofstream)
	•	String manipulation
	•	Console formatting

⸻

🗂️ Program Functionality

1️⃣ Analyze Purchase Data
	•	Reads grocery transactions from a text file
	•	Counts occurrences of each item
	•	Stores results using std::map

2️⃣ Interactive Menu Options

Users can:
	•	Search purchase frequency for a specific item
	•	Display all item frequencies
	•	View histogram visualization
	•	Exit the program safely

3️⃣ Output File Generation

Creates a structured data file containing item frequencies for persistent storage and reuse.

⸻

🧠 Concepts Demonstrated
	•	File I/O operations
	•	Associative containers (std::map)
	•	Case-insensitive string handling
	•	Modular function-based design
	•	Error handling and validation
	•	Console-based data visualization
	•	Maintainable software structure

⸻

🏗️ Design Approach

The program was designed with maintainability and readability as primary goals:
	•	Logic separated into individual functions
	•	Clear and descriptive naming conventions
	•	Consistent formatting and commenting
	•	Minimal coupling between components

This structure allows new features — such as additional menu options or alternate data sources — to be added with minimal modification to existing code.


⚙️ How to Run
g++ CornerGrocer.cpp -o CornerGrocer
Execute
./CornerGrocer

📊 Example Capabilities
	•	Analyze purchase trends
	•	Quickly look up item frequency
	•	Visualize purchasing patterns using console histograms

⸻

🎯 Purpose

This project was developed to demonstrate practical C++ programming skills through real-world data processing and structured program design. It highlights problem-solving, data organization, and clean software architecture principles.

⸻

👨‍💻 Author

Lou Carron
Software Developer | C++ | .NET | Backend Systems

GitHub: https://github.com/lourosscs50
LinkedIn: https://www.linkedin.com/in/lou-carron-2b2652123?trk=contact-info

📄 License

This project is intended for educational and portfolio demonstration purposes.
