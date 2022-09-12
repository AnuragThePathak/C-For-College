CREATE TABLE IF NOT EXISTS students (
    s_id VARCHAR(10) PRIMARY KEY,
    s_name VARCHAR(10),
    course VARCHAR(10),
    city VARCHAR(25),
    state VARCHAR(25),
    mark FLOAT
);

INSERT INTO students VALUES ("21UCS001", "ROHIT", "B.TECH", "KOLKATA", "WEST BENGAL", 7.8);
INSERT INTO students VALUES ("21UCS002", "  RAHUL", "B.TECH", "GUWAHATI", "ASSAM", 8.1);
INSERT INTO students VALUES ("21UCS003", "VINOD", "B.TECH", "NEW DELHI", "DELHI", 7.5);
INSERT INTO students VALUES ("21PCS004", "AJAY", "M.TECH", "HYDERABAD", "TELANGANA", 8.0);
INSERT INTO students VALUES ("21PCS005", "MAHESH", "M.TECH", "IMPHAL", "MANIPUR", 7.2);
INSERT INTO students VALUES ("19DCS001", "ADITYA", "PH.D", "BHUBANESWAR", "ODISHA", 9.1);