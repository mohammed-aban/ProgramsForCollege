<?php

$conn = mysqli_connect("localhost", "root", "", "student_db");

if (!$conn) {
    die("Connection error: " . mysqli_connect_error());
} else {
    echo "Connected successfully.<br><br>";
}

$create = "CREATE TABLE IF NOT EXISTS StdInfo (
    name VARCHAR(50),
    usn VARCHAR(20),
    branch VARCHAR(20),
    email VARCHAR(100),
    phone VARCHAR(15)
)";

$que = mysqli_query($conn, $create);

if (!$que) {
    echo "Table creation error: " . mysqli_error($conn) . "<br>";
}

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $name = mysqli_real_escape_string($conn, $_POST['name']);
    $usn = mysqli_real_escape_string($conn, $_POST['usn']);
    $branch = mysqli_real_escape_string($conn, $_POST['branch']);
    $email = mysqli_real_escape_string($conn, $_POST['email']);
    $phone = mysqli_real_escape_string($conn, $_POST['phone']);

    $sql = "INSERT INTO StdInfo
            (name, usn, branch, email, phone)
            VALUES
            ('$name', '$usn', '$branch', '$email', '$phone')";

    if (mysqli_query($conn, $sql)) {
        echo "Record inserted successfully.<br><br>";
    } else {
        echo "Error inserting record: " . mysqli_error($conn) . "<br>";
    }
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Student Registration</title>
</head>

<body>

    <h2>Student Registration Form</h2>

    <form action="" method="post">

        <label for="name">Name:</label>
        <input type="text" id="name" name="name" required>
        <br><br>

        <label for="usn">USN:</label>
        <input type="text" id="usn" name="usn" required>
        <br><br>

        <label for="branch">Branch:</label>
        <input type="text" id="branch" name="branch" required>
        <br><br>

        <label for="email">Email:</label>
        <input type="email" id="email" name="email" required>
        <br><br>

        <label for="phone">Phone:</label>
        <input type="text" id="phone" name="phone" required>
        <br><br>

        <input type="submit" value="Submit">

    </form>
    <hr>

    <?php

    $countQuery = mysqli_fetch_assoc(mysqli_query(
        $conn,
        "SELECT COUNT(*) AS total FROM StdInfo WHERE branch='cse'"
    ))['total'];
    echo "<h3>Total Number of CSE Students: " . $countQuery . "</h3>";

    // Display all records
    $result = mysqli_query($conn, "SELECT * FROM StdInfo");

    if (mysqli_num_rows($result) > 0) {

        echo "<table border='1' cellpadding='8'>";

        echo "
        <tr>
            <th>Name</th>
            <th>USN</th>
            <th>Branch</th>
            <th>Email</th>
            <th>Phone</th>
        </tr>
        ";

        while ($row = mysqli_fetch_assoc($result)) {

            echo "
            <tr>
                <td>" . htmlspecialchars($row['name']) . "</td>
                <td>" . htmlspecialchars($row['usn']) . "</td>
                <td>" . htmlspecialchars($row['branch']) . "</td>
                <td>" . htmlspecialchars($row['email']) . "</td>
                <td>" . htmlspecialchars($row['phone']) . "</td>
            </tr>
            ";
        }

        echo "</table>";

    } else {
        echo "No records found.";
    }

    mysqli_close($conn);

    ?>

</body>

</html>