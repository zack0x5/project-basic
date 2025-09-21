<?php
if (isset($_GET['download'])){
    echo "antivirus baixando";
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Fortigate Alert</title>
<style>
    body {
        font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
        background-color: #1a1a1a;
        color: #f2f2f2;
        display: flex;
        justify-content: center;
        align-items: center;
        height: 100vh;
        margin: 0;
    }

    .alert-container {
        background: linear-gradient(to bottom right, #ff4d4d, #ff1a1a);
        border-radius: 15px;
        padding: 40px;
        text-align: center;
        box-shadow: 0 0 20px rgba(255,0,0,0.5);
        max-width: 500px;
        width: 90%;
    }

    h1 {
        font-size: 2.2rem;
        margin-bottom: 20px;
        text-shadow: 2px 2px 5px #000;
    }

    p {
        font-size: 1.1rem;
        margin-bottom: 30px;
    }

    .button {
        background-color: #fff;
        color: #ff1a1a;
        border: none;
        padding: 15px 30px;
        font-size: 1rem;
        border-radius: 8px;
        cursor: pointer;
        font-weight: bold;
        transition: 0.3s;
        box-shadow: 0 4px 6px rgba(0,0,0,0.3);
    }

    .button:hover {
        background-color: #ffe6e6;
        transform: scale(1.05);
    }
</style>
</head>
<body>
    <div class="alert-container">
        <h1>⚠ Fortigate Firewall Alert</h1>
        <p>Nossa análise detectou atividades potencialmente maliciosas em seu sistema, indicando que informações confidenciais, incluindo dados de contas e arquivos pessoais, podem ter sido comprometidas. 
           Para mitigar riscos imediatos e proteger a integridade de seus dados, é altamente recomendável baixar e executar o antivírus oficial imediatamente. A adoção dessa medida preventiva é essencial para garantir a segurança contínua do seu ambiente digital.</p>
        <button class="button" name="download">Baixar antivírus</button>
    </div>
</body>
</html>
