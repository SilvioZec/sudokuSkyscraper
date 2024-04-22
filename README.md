Projeto em C++ para resolver automaticamente matrizes do tipo sudoku skyscrapper.
Regras para solução:

Sobre Skyscraper Sudoku

"Skyscraper Sudoku" é uma variante do clássico Sudoku e contém pistas adicionais fora da grade. Cada dígito em uma célula representa a altura do arranha-céu naquela célula. As pistas fora da grade indicam o número de arranha-céus visíveis a partir daquela célula. Um arranha-céu esconde todos os outros atrás dele que têm altura igual ou menor.

Regras Básicas
- Preencher a Grade: Preencha a grade com dígitos de modo que cada linha, coluna e região especificada contenha os números de 1 até o tamanho da grade (por exemplo, 1-9 para uma grade 9x9).
- Números Únicos: Cada número deve ser único em cada linha, coluna e região especificada.
- Pistas de Arranha-Céu: Atenda às pistas de arranha-céu fora da grade, que indicam quantos arranha-céus podem ser vistos a partir daquele ponto, considerando que os mais altos escondem os mais baixos atrás deles.

Regras Adicionais
Visibilidade: Um arranha-céu mais alto esconde todos os arranha-céus mais baixos ou da mesma altura atrás dele.
Adesão às Pistas: Todas as pistas fornecidas devem ser satisfeitas pela solução final da grade.
