CREATE DATABASE lab;
USE lab;
CREATE TABLE IF NOT EXISTS students (
     s_id VARCHAR(10) PRIMARY KEY,
     s_name VARCHAR(10),
     course VARCHAR(10),
     city VARCHAR(25),
     state VARCHAR(25),
     mark FLOAT
);
INSERT INTO students
VALUES (
          "21UCS001",
          "ROHIT",
          "B.TECH",
          "KOLKATA",
          "WEST BENGAL",
          7.8
     ),
     (
          "21UCS002",
          "  RAHUL",
          "B.TECH",
          "GUWAHATI",
          "ASSAM",
          8.1
     ),
     (
          "21UCS003",
          "VINOD",
          "B.TECH",
          "NEW DELHI",
          "DELHI",
          7.5
     ),
     (
          "21PCS001",
          "AJAY",
          "M.TECH",
          "HYDERABAD",
          "TELANGANA",
          8.0
     ),
     (
          "21PCS005",
          "MAHESH",
          "M.TECH",
          "IMPHAL",
          "MANIPUR",
          7.2
     ),
     (
          "19DCS001",
          "ADITYA",
          "PH.D",
          "BHUBANESWAR",
          "ODISHA",
          9.1
     );
CREATE TABLE IF NOT EXISTS teachers (
     t_id VARCHAR(10) PRIMARY KEY,
     t_name VARCHAR(10),
     city VARCHAR(25),
     state VARCHAR(25)
);
INSERT INTO teachers
VALUES (
          "20FCS001",
          "LALIT",
          "CHENNAI",
          "TAMLI NADU"
     ),
     (
          "19FCS003",
          "AMIT",
          "HYDERABAD",
          "TELANGANA"
     ),
     (
          "21FCS012",
          "VENKAT",
          "GUWAHATI",
          "ASSAM"
     );
CREATE TABLE IF NOT EXISTS guided (
     g_id VARCHAR(10),
     g_date DATE,
     g_year INT,
     s_id VARCHAR(10),
     t_id VARCHAR(10),
     PRIMARY KEY (
          g_id,
          s_id,
          t_id
     ),
     FOREIGN KEY (s_id) REFERENCES students (s_id) ON UPDATE RESTRICT ON DELETE CASCADE,
     FOREIGN KEY (t_id) REFERENCES teachers (t_id) ON UPDATE RESTRICT ON DELETE CASCADE
);
INSERT INTO guided
VALUES (
          "21CS01",
          "21-02-02",
          2021,
          "21UCS001",
          "20FCS001"
     ),
     (
          "19CS01",
          "19-06-19",
          2019,
          "19DCS001",
          "19FCS003"
     ),
     (
          "21CS02",
          "21-06-02",
          2021,
          "21UCS002",
          "21FCS012"
     ),
     (
          "21CS03",
          "21-06-02",
          2021,
          "21UCS003",
          "20FCS001"
     ),
     (
          "21CS04",
          "21-07-02",
          2021,
          "21PCS001",
          "21FCS012"
     ),
     (
          "21CS05",
          "21-02-02",
          2021,
          "21PCS005",
          "19FCS003"
     );

SELECT * FROM students;
SELECT * FROM teachers;
SELECT * FROM guided;

-- questions 1
SELECT g_id, g_year, g_date FROM guided;

-- question 2
SELECT * FROM guided WHERE t_id = "19FCS003";

-- question 3
SELECT city, s_name, state, marks, s_id, course FROM students;

-- question 4
SELECT mark, s_name FROM students ORDER BY mark DESC;

-- question 5
SELECT * FROM guided WHERE (g_year > 2019 OR NOT (g_date = "2021-06-02"));

-- question 6
SELECT s_name, city FROM students WHERE (mark > 7 AND (state = "ASSAM" OR state = "DELHI"));

-- question 7
SELECT * FROM students WHERE NOT mark <= 8;

-- question 8
CREATE TABLE IF NOT EXISTS employees (
     id SMALLINT,
     dept_id SMALLINT,
     gender CHAR(1),
     e_name VARCHAR(10) UNIQUE,
     salary INTEGER,
     e_id INTEGER PRIMARY KEY
);

INSERT IGNORE INTO employees VALUES
(1, 2, "M", "JOHN", 1000, 123),
(2, 4, "F", "BELA", 2000, 313),
(3, 3, "F", "KATY", 2000, 335),
(4, 1, "M", "RON", 2000, 533),
(5, 2, "M", "KEN", 1000, 563),
(6, 2, "M", "JOHN", 2000, 321),
(7, 4, "F", "TAYLOR", 1000, 312),
(8, 3, "F", "TAYLOR", 2000, 442),
(9, 3, "M", "RAZOR", 1000, 565);

SELECT e_name, gender FROM employees;

-- question 9
SELECT s_name, s_id FROM students WHERE mark >=8;
