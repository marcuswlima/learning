# 3 Getting to Know CSS

## The Cascade

All styles will cascade from the top of our style sheet to the bottom of our style sheet.

## Calculating Specificity

| Select | weight  | 
| ---      |  ------  |
| type | `0-0-1`
| class | `0-1-0`
| id | `1-0-0`

What’s important to note here is that the ID selector has a higher specificity weight than the class selector, and the class selector has a higher specificity weight than the type selector.

## Combining Selectors
