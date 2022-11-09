CREATE TABLE [dbo].[Dim_Tempo]
(
  [Cod_Dia] NVARCHAR(50) ,
  [Data] DATE  ,
  [Cod_Semana] INT ,
  [Nome_Dia_Semana] NVARCHAR(50) ,
  [Cod_Mes] INT ,
  [Nome_Mes] NVARCHAR(50) ,
  [Cod_Mes_Ano] NVARCHAR(50) ,
  [Nome_Mes_Ano] NVARCHAR(50) ,
  [Cod_Trimestre] INT  ,
  [Nome_Trimestre] NVARCHAR(50),
  [Cod_Trimestre_Ano] INT  ,
  [Nome_Trimestre_Ano] NVARCHAR(50),
  [Cod_Semestre] INT  ,
  [Nome_Semestre] NVARCHAR(50),
  [Cod_Semestre_Ano] NVARCHAR(50),
  [Nome_Semestre_Ano] NVARCHAR(50),
  [Ano] NVARCHAR(50)  ,
  [Tipo_Dia] NVARCHAR(50),
  CONSTRAINT pk_Dim_Tempo PRIMARY KEY ([Cod_Dia])
)
