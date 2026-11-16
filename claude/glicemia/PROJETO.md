# Glicemia — Definição do Projeto

> Documento de premissas e requisitos levantados em entrevista (15/11/2026).
> Serve como referência para o desenvolvimento e para sessões futuras com IA.

## 1. Visão geral

App web responsivo para **registrar e acompanhar glicemia e doses de insulina** de uma pessoa com **Diabetes Tipo 1**, para uso **pessoal/familiar** no dia a dia. Precisa ser confiável, rápido de usar no celular e funcionar sem internet.

O app **registra e mostra** os dados. Ele **não dá recomendações médicas nem calcula doses**.

## 2. Premissas

| Tema | Decisão |
|---|---|
| Público | Uso pessoal/familiar |
| Tipo de diabetes | Tipo 1 |
| Contas | Uma pessoa por conta (sem perfis múltiplos nem compartilhamento) |
| Objetivo | Ferramenta real de uso diário |
| Medição | Glicosímetro (dedo), com registro manual |
| Insulina | Forma de aplicação indefinida: registro manual genérico (sem integração com bomba) |
| Cálculo de dose | **Não**. O app só registra |
| Plataformas | Navegador em desktop e celular, qualquer tamanho de tela |
| Offline | **Sim**: PWA instalável, registra offline e sincroniza depois |
| Idioma / unidade | Português (pt-BR), somente **mg/dL** |
| Stack | Back-end em Python + front-end em JavaScript (frameworks a definir) |
| Login | E-mail e senha |
| Hospedagem | A definir |

## 3. Glossário (para quem está começando)

- **Glicemia**: concentração de glicose (açúcar) no sangue, em mg/dL.
- **Hipoglicemia (hipo)**: glicemia baixa, abaixo de 70 mg/dL. Abaixo de 54 é considerada grave. É o risco mais perigoso no curto prazo.
- **Hiperglicemia (hiper)**: glicemia alta, acima da faixa-alvo. Acima de ~250 mg/dL pede atenção.
- **Faixa-alvo**: intervalo considerado adequado, definido pelo médico. A referência comum é 70–180 mg/dL.
- **Insulina basal**: ação lenta, aplicada 1–2x ao dia (ex.: Tresiba, Lantus, Basaglar).
- **Insulina rápida / bolus**: aplicada nas refeições ou para corrigir glicemia alta (ex.: Fiasp, Humalog, Novorapid, Apidra).
- **Tempo no alvo (TIR)**: % das medições dentro da faixa-alvo.
- **HbA1c (hemoglobina glicada)**: exame de laboratório que reflete a média dos últimos ~3 meses. Fora do escopo da v1.

## 4. Funcionalidades da v1 (MVP)

### 4.1 Conta
- Cadastro e login com e-mail e senha.
- Recuperação de senha por e-mail.
- Logout. A sessão continua ativa no celular para não exigir login a cada uso.

### 4.2 Registro de glicemia
- Campos: **valor (mg/dL)**, **data/hora** (padrão: agora, editável), **momento**, **observação** opcional.
- Momentos (lista fixa):
  - Jejum
  - Antes do café / Depois do café
  - Antes do almoço / Depois do almoço
  - Antes do jantar / Depois do jantar
  - Antes de dormir
  - Madrugada
  - Outro
- Validação: aceitar valores entre 20 e 600 mg/dL (faixa típica dos glicosímetros) e pedir confirmação para valores extremos.
- Editar e excluir registros.

### 4.3 Registro de insulina
- Campos: **tipo** (basal ou rápida), **nome da insulina** (opcional, lista sugerida + texto livre), **unidades** (aceitar meias unidades, ex.: 2,5 U), **data/hora**, **observação** opcional.
- Editar e excluir registros.

### 4.4 Faixa-alvo e cores
- Faixa configurável pelo usuário. Valores padrão:

| Classificação | Faixa (padrão) | Cor |
|---|---|---|
| Muito baixa | < 54 | Vermelho escuro |
| Baixa | 54–69 | Vermelho |
| No alvo | 70–180 | Verde |
| Alta | 181–250 | Amarelo/laranja |
| Muito alta | > 250 | Laranja escuro/roxo |

- **Acessibilidade:** cor nunca é o único sinal. Cada valor também leva um ícone ou texto ("baixa", "alta") para quem tem daltonismo.
- Sem notificações nem orientações automáticas na v1, apenas destaque visual.

### 4.5 Histórico e relatórios
- **Lista/linha do tempo** com glicemias e insulinas intercaladas por dia.
- **Gráfico de glicemia ao longo do tempo**, com a faixa-alvo sombreada e pontos coloridos por classificação. Períodos: 7, 14, 30 e 90 dias.
- **Estatísticas por período**: média, desvio padrão, mínimo/máximo, nº de medições, % no alvo / abaixo / acima, nº de hipoglicemias e total diário médio de insulina (basal e rápida).

### 4.6 Exportação
- **Relatório em PDF** para levar ao médico, com: período, estatísticas resumo, gráfico e tabela de registros.

### 4.7 PWA / offline
- Instalável na tela inicial (Android e iOS).
- Registrar, ver e editar sem internet. Os dados ficam no dispositivo (IndexedDB) e são sincronizados quando a conexão volta.
- Indicador visível de "pendente de sincronização".
- Conflitos: o último a editar prevalece (*last write wins*), com registros identificados por UUID gerado no cliente.

## 5. Requisitos não funcionais

- **Responsivo / mobile-first**: telas de ~320px até desktop largo, botões grandes e campo numérico com teclado numérico no celular.
- **Registro rápido**: lançar uma glicemia em poucos toques (meta: menos de 10 segundos).
- **Privacidade (LGPD)**: dados de saúde são dados pessoais sensíveis.
  - HTTPS obrigatório
  - senhas com hash forte (argon2 ou bcrypt)
  - cada usuário acessa só os próprios dados
  - possibilidade de exportar e excluir todos os dados da conta
- **Backup**: rotina de backup do banco de dados no servidor.
- **Fuso horário**: datas armazenadas em UTC e exibidas no fuso do usuário.
- **Aviso** visível: "Este app não substitui orientação médica."

## 6. Fora do escopo da v1

- Cálculo/sugestão de dose de insulina (calculadora de bolus).
- Integração com sensores contínuos (CGM/Libre), bombas de insulina ou glicosímetros Bluetooth.
- Registro de carboidratos/refeições, atividade física e sintomas.
- Lembretes e notificações.
- HbA1c estimada e análise de padrões por momento do dia.
- Exportação CSV.
- Múltiplos perfis, compartilhamento com familiares ou médicos.
- Login social (Google).
- Outros idiomas e unidade mmol/L.

## 7. Ideias para versões futuras

- Registro de carboidratos, atividade física e notas de sintomas (ajudam a explicar variações).
- Média por momento do dia ("sempre alto depois do almoço").
- Lembretes (ex.: basal às 22h).
- Exportação CSV.
- Orientação na hipoglicemia (ex.: "regra dos 15": 15 g de carboidrato rápido e medir de novo em 15 min).
- Faixa-alvo diferente por momento do dia.

## 8. Modelo de dados inicial (rascunho)

```
User
  id, email, password_hash, created_at

Settings (1:1 User)
  user_id, very_low_limit=54, low_limit=70, high_limit=180, very_high_limit=250, timezone

GlucoseReading
  id (UUID), user_id, value_mg_dl (int), measured_at (UTC), moment (enum), note,
  created_at, updated_at, deleted_at (soft delete, ajuda na sincronização offline)

InsulinDose
  id (UUID), user_id, kind (basal|rapid), insulin_name, units (decimal 0.5),
  applied_at (UTC), note, created_at, updated_at, deleted_at
```

## 9. Questões em aberto

- [ ] Frameworks específicos: back-end (FastAPI ou Django?) e front-end (React, Vue, Svelte ou HTMX?). Considerar o suporte a PWA offline na escolha.
- [ ] Banco de dados (PostgreSQL sugerido para produção; SQLite para desenvolvimento).
- [ ] Hospedagem e domínio.
- [ ] Forma de aplicação da insulina (caneta ou bomba), que pode mudar o que vale registrar.
- [ ] Faixa-alvo real indicada pelo médico do usuário.
- [ ] Serviço de envio de e-mail (recuperação de senha).

