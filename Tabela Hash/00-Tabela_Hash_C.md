
  

# Uso de Tabela Hash em C

  

## Introdução

As tabelas hash são estruturas de dados eficientes para armazenar e buscar dados rapidamente. Elas utilizam uma função de hash para mapear chaves a valores correspondentes, permitindo operações de busca, inserção e deleção em tempo constante no melhor caso.

  

## Objetivos

- Entender o conceito de tabela hash.

- Implementar uma tabela hash em C.

- Realizar operações básicas: inserção, busca e remoção.

  

## Estrutura do Tutorial

1. Conceitos Básicos

2. Função de Hash

3. Estrutura da Tabela Hash

4. Implementação em C

5. Testando a Tabela Hash

6. Conclusão

  

## 1. Conceitos Básicos

Uma tabela hash é uma estrutura de dados que associa chaves a valores usando uma função de hash. A função de hash transforma a chave em um índice de um array onde o valor será armazenado.

  

## 2. Função de Hash

A função de hash deve distribuir uniformemente as chaves para minimizar colisões. Uma função de hash simples para strings pode ser a soma dos valores ASCII dos caracteres.

  

```c

unsigned int hash(const char *key) {
  unsigned int hash = 0;

  while (*key) {
    hash += *key++;
  }

  return hash;
}

```

  

## 3. Estrutura da Tabela Hash

Uma tabela hash pode ser implementada usando um array de listas encadeadas para lidar com colisões (método de encadeamento).

  

```c


#define TABLE_SIZE 100

typedef struct Entry
{
	char *key;

	int value;

	struct Entry * next;

}

Entry;

typedef struct
{
	Entry *entries[TABLE_SIZE];

}

HashTable;
```

  

## 4. Implementação em C

  

### 4.1. Inicialização

Inicialize a tabela hash definindo todos os ponteiros como NULL.

  

```c

HashTable* create_table()
{
	HashTable *table = malloc(sizeof(HashTable));

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		table->entries[i] = NULL;
	}

	return table;

}

```

  

### 4.2. Inserção

Para inserir um par chave-valor, calcule o índice usando a função de hash e adicione o novo par à lista encadeada no índice apropriado.

  

```c

void insert(HashTable *table, const char *key, int value)
{
	unsigned int index = hash(key) % TABLE_SIZE;

	Entry *entry = malloc(sizeof(Entry));

	entry->key = strdup(key);

	entry->value = value;

	entry->next = table->entries[index];

	table->entries[index] = entry;

}

```

  

### 4.3. Busca

Para buscar um valor, use a função de hash para encontrar o índice e percorra a lista encadeada no índice até encontrar a chave.

  

```c

int search(HashTable *table, const char *key)
{
	unsigned int index = hash(key) % TABLE_SIZE;

	Entry *entry = table->entries[index];

	while (entry != NULL)
	{
		if (strcmp(entry->key, key) == 0)
		{
			return entry->value;
		}

		entry = entry->next;
	}

	return -1;	// Indica que a chave não foi encontrada

}

```

  

### 4.4. Remoção

Para remover um par chave-valor, encontre o índice usando a função de hash e remova a entrada correspondente da lista encadeada.

  

```c

void delete(HashTable *table, const char *key)
{
	unsigned int index = hash(key) % TABLE_SIZE;

	Entry *entry = table->entries[index];

	Entry *prev = NULL;

	while (entry != NULL && strcmp(entry->key, key) != 0)
	{
		prev = entry;

		entry = entry->next;
	}

	if (entry == NULL)
	{
		return;	// A chave não foi encontrada

	}

	if (prev == NULL)
	{
		table->entries[index] = entry->next;
	}
	else
	{
		prev->next = entry->next;
	}

	free(entry->key);

	free(entry);

}

```

  

## 5. Testando a Tabela Hash

Aqui está um exemplo de como testar a implementação da tabela hash.

  

```c

int main() {

	HashTable *table = create_table();

	insert(table, "key1", 1);

	insert(table, "key2", 2);

	insert(table, "key3", 3);

	printf("Value for 'key1': %d\n", search(table, "key1"));

	printf("Value for 'key2': %d\n", search(table, "key2"));

	printf("Value for 'key3': %d\n", search(table, "key3"));

	delete(table, "key2");

	printf("Value for 'key2' after deletion: %d\n", search(table, "key2"));

	return 0;

}

```

  

## 6. Conclusão

Nesta aula obrimos os conceitos básicos de tabelas hash e implementamos uma tabela hash em C, incluindo funções para inserção, busca e remoção. As tabelas hash são uma poderosa ferramenta para otimizar operações de busca e são amplamente usadas em várias aplicações de software.