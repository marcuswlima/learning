CREATE TABLE [dbo].[Dim_Cliente]
(
	Cod_Cliente NVARCHAR(50)  ,
	Desc_Cliente NVARCHAR(250) ,
  	Cod_cidade NVARCHAR(50) ,
	Desc_Cidade NVARCHAR(250),
	[Cod_Estado] NVARCHAR(50) ,
	Desc_Estado NVARCHAR(250),
	Cod_Regiao NVARCHAR(50) ,
	Desc_Regiao NVARCHAR(250),
	Cod_Segmento NVARCHAR(50) ,
	Desc_Segmento NVARCHAR(250) ,
    CONSTRAINT PK_Dim_Cliente PRIMARY KEY (Cod_Cliente) 
)
