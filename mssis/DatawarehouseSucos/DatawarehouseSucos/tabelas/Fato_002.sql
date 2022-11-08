CREATE TABLE [dbo].[Fato_002]
(
  Cod_Cliente NVARCHAR(50) ,
  Cod_Produto NVARCHAR(50),
  Cod_Fabrica NVARCHAR(50) ,
  Cod_Dia NVARCHAR(50) ,
  Frete FLOAT NOT NULL,
  CONSTRAINT PK_Fato_002             PRIMARY KEY (Cod_Cliente, Cod_Produto, Cod_Fabrica, Cod_Dia ),
  CONSTRAINT FK_Fato_002_Dim_Cliente FOREIGN KEY (Cod_Cliente) REFERENCES Dim_Cliente,
  CONSTRAINT FK_Fato_002_Dim_Produto FOREIGN KEY (Cod_Produto) REFERENCES Dim_Produto,
  CONSTRAINT FK_Fato_002_Dim_Fabrica FOREIGN KEY (Cod_Fabrica) REFERENCES Dim_Fabrica,
  CONSTRAINT FK_Fato_002_Dim_Tempo   FOREIGN KEY (Cod_Dia)     REFERENCES Dim_Tempo
)
