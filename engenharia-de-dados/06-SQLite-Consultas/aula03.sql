select * 
from clientes;

.schema clientes

SELECT Nome, Preco
FROM produtos
GROUP BY Nome, Preco
HAVING Preco > (
SELECT AVG(Preco) 
FROM produtos);