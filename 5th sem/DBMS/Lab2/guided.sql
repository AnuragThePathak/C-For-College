CREATE TABLE IF NOT EXISTS guided (
    g_id VARCHAR(10),
    g_date DATE,
    g_year INT,
    s_id VARCHAR(10),
    t_id VARCHAR(10),
    PRIMARY KEY (g_id, s_id, t_id),
    FOREIGN KEY (s_id) REFERENCES students (s_id) ON UPDATE RESTRICT ON DELETE CASCADE,
    FOREIGN KEY (t_id) REFERENCES teachers (t_id) ON UPDATE RESTRICT ON DELETE CASCADE
);

INSERT INTO guided VALUES
    ("21CS01", "21-02-02", 2021, "21UCS001", "20FCS001"),
    ("19CS01", "19-06-19", 2019, "19DCS001", "19FCS003"),
    ("21CS02", "21-06-02", 2021, "21UCS002", "21FCS012"),
    ("21CS03", "21-06-02", 2021, "21UCS003", "20FCS001"),
    ("21CS04", "21-07-02", 2021, "21PCS001", "21FCS012"),
    ("21CS05", "21-02-02", 2021, "21PCS005", "19FCS003");
