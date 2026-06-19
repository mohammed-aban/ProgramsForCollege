<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title>Palindrome</title>
        <style>
           body {
                display: flex;
                flex-direction: column;
                justify-content: center;
                align-items: center;
                height: 100vh;
                margin: 0;
                background-color: #c4c6d7;
                color: #333;
            }
        </style>
    </head>
    <body>
        <form method="post">
            Enter the number :
            <input type="text" name="number">
            <input type="submit" value="check">
        </form>
        <?php
        if($_SERVER["REQUEST_METHOD"]=="POST") {
                $num = $_POST["number"];
                $temp = $num;
                $sum=0;
                $reverse=0;
                while($temp>0) {
                        $digits=$temp%10;
                        $sum += $digits;
                        $reverse=($reverse*10)+$digits;
                        $temp=(int)($temp/10);
                    }
                    echo"<bold>result is:<bold><br>";
                    echo"sum of digits: ".$sum."<br>";
                    if($num==$reverse)
                            echo " the number is palindrome";
                    else
                        echo "the number is not a palindrome number";
                    
            }
            ?>
    </body>
</html>