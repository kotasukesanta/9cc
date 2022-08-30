#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Token Token;

// 抽象構文木のノードの種類
typedef enum {
  ND_ADD,    // +
  ND_SUB,    // -
  ND_MUL,    // *
  ND_DIV,    // /
  ND_ASSIGN, // =
  ND_LVAR,   // ローカル変数
  ND_NUM,    // 整数
  ND_EQ,     // ==
  ND_NE,     // !=
  ND_LT,     // <
  ND_LTE,    // <=
  ND_RETURN, // return
} NodeKind;

typedef struct Node Node;

struct Node {
  NodeKind kind; // ノードの型
  Node *lhs;     // 左辺
  Node *rhs;     // 右辺
  int val;       // kindがND_NUMの場合のみ使う
  int offset;    // kindがND_LVARの場合のみ使う
};

extern Token *token;

extern char *user_input;

extern Node *code[100];

Token *tokenize(char *p);

Node *expr();

void program();

void gen(Node *node);

void error(char *fmt, ...);
