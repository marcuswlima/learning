CREATE TABLE [dbo].[Fato_003]
(
  Cod_Fabrica NVARCHAR(50) ,
  Cod_Dia     NVARCHAR(50) ,
  Custo_Fixo  FLOAT NOT NULL,
  CONSTRAINT PK_Fato_003             PRIMARY KEY (Cod_Fabrica, Cod_Dia ),
  CONSTRAINT FK_Fato_003_Dim_Fabrica FOREIGN KEY (Cod_Fabrica) REFERENCES Dim_Fabrica,
  CONSTRAINT FK_Fato_003_Dim_Tempo   FOREIGN KEY (Cod_Dia)     REFERENCES Dim_Tempo
)
