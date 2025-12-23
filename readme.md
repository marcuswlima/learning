## Programing
- C++
- Phyton

## Produção Musical
- LMMS
- Audacity
- Video ???

## ContraBaixo
- Billè
- Robert Antony
- Pffeifer

## Lunix
- Packing System
- Initialization


# `PCK_ARRECADACAO_DIM`

## Interface `DIM-CartorioExtrajudicial`

- Propagar (insert e update) dos dados de `arrecadacao.PARRCARTORIO` para `dimensional.unidade`

## Procedure `arrecadacao`

Passos:

1. `extrajudicial-variavel-dim`

   - Insert em dimensional.fatoarrecadacaoextrajud de todas as variáveis da categoria 86 

```SQL
BEGIN
dimensional.PCKNUMEROJUSTICA.JUSTICANUMEROS_ODI_ARR_JUD_EXT(sysdate);
END;
```

2. `judicial-variavel-dim`

   - Insert em dimensional.fatoarrecadacaojud de todas as variáveis da categoria 85

```SQL
BEGIN
dimensional.pcknumerojustica.JusticaNumeros_ODI_ARR_JUD(sysdate);
END;
```

## Procedure `pIndicadores-unaj`

Passos:

1. `Indicadore UNAJ`

   - Insert em `dimensional.fatotxcongestunaj` das variaives  4077--CNPjUnaj, 4078--TBaixPjUnaj,  4080 --CNPacUnaj, 4081--TBaixPacUnaj,  4079--CPPjUnaj e  4082--CPPacUnaj 

```SQL
begin
   DIMENSIONAL.PCKNUMEROJUSTICA.EXECUTACATEGORIAUNAJ();
end;
```

2. `Qualificação CPPac em Tarefas e Boletos de Cobrança Administrativa`

   - Insert em dimensional.fatoarrecadacaojud de todas as variáveis da categoria 85

```SQL
begin
   DIMENSIONAL.pck_pac.processamentoDiario(); 
end;
```
