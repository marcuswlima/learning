CREATE TABLE [dbo].[Fato_004]
(
  [Cod_Cliente] NVARCHAR(50) ,
  [Cod_Produto] NVARCHAR(50),
  [Cod_Organizacional] NVARCHAR(50),
  [Cod_Dia] NVARCHAR(50) ,
  [Meta_Faturamento] FLOAT NOT NULL,
  CONSTRAINT PK_Fato_004 PRIMARY KEY  (Cod_Cliente,[Cod_Produto], [Cod_Organizacional], [Cod_Dia]),
  CONSTRAINT FK_Fato_004_Dim_Cliente        FOREIGN KEY (Cod_Cliente)        REFERENCES Dim_Cliente,
  CONSTRAINT FK_Fato_004_Dim_Produto        FOREIGN KEY (Cod_Produto)        REFERENCES Dim_Produto,
  CONSTRAINT FK_Fato_004_Dim_Organizacional FOREIGN KEY (Cod_Organizacional) REFERENCES Dim_Organizacional,
  CONSTRAINT FK_Fato_004_Dim_Tempo          FOREIGN KEY (Cod_Dia)            REFERENCES Dim_Tempo
)
