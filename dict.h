#ifndef DICT_H
#define DICT_H

/**
 * struct dictItem_s - an item key/value of the dictionnary
 *
 * @key: the key of the structure which is unique for all the dictionnary
 * @value: the value of the key
 * @next: the next node
 */
typedef struct dictItem_s
{
	char *key;
	char *value;
	dict_t *next;
} dictItem_t;


/**
 * struct dict_s - a dictionnary like structure
 *
 * @len: the length of the dictionnary
 * @head: the head of the dictionnary
 */
typedef struct dict_s
{
	unsigned int len;
	dictItem_t *head;
} dict_t;


dictItem_t *createDictItem(char *key, char *value);
void deleteDictItem(dict_t *dict, dictItem_t *item);
dict_t *setDictValue(dict_t *dict, char *key, char *value);
dict_t *getDictValue(dict_t *dict, char *key, char **value);


#endif /* DICT_H */
