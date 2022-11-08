CREATE TABLE [dbo].[Fato_001]
(
  [Cod_Cliente] NVARCHAR(50) ,
  [Cod_Produto] NVARCHAR(50),
  [Cod_Organizacional] NVARCHAR(50),
  [Cod_Fabrica] NVARCHAR(50) ,
  [Cod_Dia] NVARCHAR(50) ,
  [Faturamento] FLOAT NOT NULL,
  [Imposto] FLOAT NOT NULL,
  [Custo_Variavel] FLOAT NOT NULL,
  [Unidade_vendida] FLOAT NOT NULL,
  [Quantidade_Vendida] FLOAT NOT NULL,
  CONSTRAINT PK_Fato_001 PRIMARY KEY  (Cod_Cliente, Cod_Produto, Cod_Organizacional, Cod_Fabrica, Cod_Dia),
  CONSTRAINT FK_Fato_001_Dim_Cliente        FOREIGN KEY (Cod_Cliente)        REFERENCES Dim_Cliente,
  CONSTRAINT FK_Fato_001_Dim_Produto        FOREIGN KEY (Cod_Produto)        REFERENCES Dim_Produto,
  CONSTRAINT FK_Fato_001_Dim_Organizacional FOREIGN KEY (Cod_Organizacional) REFERENCES Dim_Organizacional,
  CONSTRAINT FK_Fato_001_Dim_Fabrica        FOREIGN KEY (Cod_Fabrica)        REFERENCES Dim_Fabrica,
  CONSTRAINT FK_Fato_001_Dim_Tempo          FOREIGN KEY (Cod_Dia)            REFERENCES Dim_Tempo
)
