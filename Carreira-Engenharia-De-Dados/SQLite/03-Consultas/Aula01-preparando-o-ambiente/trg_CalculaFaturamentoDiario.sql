CREATE TRIGGER CalculaFaturamentoDiario
AFTER INSERT ON itenspedidos
FOR EACH ROW
BEGIN
    DELETE FROM FaturamentoDiario;
    INSERT INTO FaturamentoDiario (Dia, FaturamentoTotal)
        SELECT DATE(datahorapedido) AS Dia, SUM(ip.precounitario) AS FaturamentoDiario
        FROM pedidos p
        JOIN itenspedidos ip ON p.id = ip.idpedido
        GROUP BY Dia
        ORDER BY Dia;
END;