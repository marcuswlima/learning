CREATE TABLE [dbo].[Fato_005]
(
  [Cod_Produto] NVARCHAR(50),
  [Cod_Fabrica] NVARCHAR(50) ,
  [Cod_Dia] NVARCHAR(50) ,
  [Meta_Custo] FLOAT NOT NULL 
  CONSTRAINT PK_Fato_005             PRIMARY KEY (Cod_Produto, Cod_Fabrica, Cod_Dia),
  CONSTRAINT FK_Fato_005_Dim_Produto FOREIGN KEY (Cod_Produto) REFERENCES Dim_Produto,
  CONSTRAINT FK_Fato_005_Dim_Fabrica FOREIGN KEY (Cod_Fabrica) REFERENCES Dim_Fabrica,
  CONSTRAINT FK_Fato_005_Dim_Tempo   FOREIGN KEY (Cod_Dia)     REFERENCES Dim_Tempo
)
