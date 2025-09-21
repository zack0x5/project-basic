<?php
if (isset($_POST['download'])){
    $filename = "cliques.txt";
    $cliques = file_get_contents($filename);
    $cliques++;
    file_put_contents($filename, $cliques);
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Fortigate Download</title>
</head>
<body>
    <h1>Baixando antivírus...</h1>
</body>
</html>