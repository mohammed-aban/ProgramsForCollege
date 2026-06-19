<?xml version="1.0"?>

<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">

<html>

<head>

<title>Student Information</title>

<style>

body{
    font-family:Arial;
    background-color:#f4f4f4;
}

.box{
    width:400px;
    margin:auto;
    border:2px solid black;
    padding:20px;
    background:white;
}

h2{
    text-align:center;
    color:blue;
}

p{
    font-size:18px;
}

</style>

</head>

<body>

<div class="box">

<h2>Student Details</h2>

<p>
<b>USN :</b>
<xsl:value-of select="student/usn"/>
</p>

<p>
<b>Name :</b>
<xsl:value-of select="student/name"/>
</p>

<p>
<b>College :</b>
<xsl:value-of select="student/college"/>
</p>

<p>
<b>Branch :</b>
<xsl:value-of select="student/branch"/>
</p>

<p>
<b>Year :</b>
<xsl:value-of select="student/year"/>
</p>

<p>
<b>Email :</b>
<xsl:value-of select="student/email"/>
</p>

</div>

</body>

</html>

</xsl:template>

</xsl:stylesheet>