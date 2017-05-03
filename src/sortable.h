#ifndef __RS_SORTABLE_H__
#define __RS_SORTABLE_H__

#pragma pack(1)

#define RS_SORTABLE_NUM 1
#define RS_SORTABLE_EMBEDDED_STR 2
#define RS_SORTABLE_STR 3
// nil value means the value is empty
#define RS_SORTABLE_NIL 4

typedef struct {
  unsigned char len;
  char data[7];
} RSEmbeddedStr;

typedef struct {
  union {
    // RSEmbeddedStr embstr;
    char *str;
    double num;
  };
  int type : 8;
} RSSortableValue;

typedef struct {
  unsigned int len : 8;
  RSSortableValue values[];
} RSSortingVector;

typedef struct {
  int len : 8;
  const char *fields[];
} RSSortingTable;

RSSortingTable *NewSortingTable(int len);

void SortingTable_SetFieldName(RSSortingTable *tbl, int idx, const char *name);

int RSSortingTable_GetFieldIdx(RSSortingTable *tbl, const char *field);

int RSSortingVector_Cmp(RSSortingVector *self, RSSortingVector *other, int idx);

void RSSortingVector_Put(RSSortingVector *tbl, int idx, void *p, int type);

RSSortingVector *NewSortingVector(int len);

#pragma pack()

#endif