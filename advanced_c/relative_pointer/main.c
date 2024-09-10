#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#include "./fruits.h"

typedef struct Node Node;

//struct Node {
//  char text[32];
//  uint16_t *left;  // relative pointer, relative to the beginning of the array
//  uint16_t *right;
//};

struct Node {
  char text[32];
  Node *left;
  Node *right;
};

#define NODE_POOL_CAP 1024
typedef struct {
  size_t sz;
  Node nodes[NODE_POOL_CAP];
} Node_Pool;

static Node_Pool global_node_pool = {0};

Node *node_pool_alloc(Node_Pool *np) {
  assert(np->sz < NODE_POOL_CAP);
  Node *result = &np->nodes[np->sz];
  memset(result, 0, sizeof(Node));
  np->sz += 1;
  return result;
}

void node_set_text(Node *node, const char *text_cstr) {
  size_t n = strlen(text_cstr);
  if (n > sizeof(node->text) - 1) {
    n = sizeof(node->text) - 1;
  }
  memset(node->text, 0, sizeof(node->text));
  memcpy(node->text, text_cstr, n);
}

Node *node_pool_alloc_with_text(Node_Pool *np, const char *text_cstr) {
  Node *result = node_pool_alloc(np);
  node_set_text(result, text_cstr);
  return result;
}

void print_tree(FILE *stream, Node *node, size_t level) {
  for (size_t i = 0; i < level; ++i)
    fputs(" ", stream);
  fputs(node->text, stream);
  fputc('\n', stream);
  if (node->left)
    print_tree(stream, node->left, level + 1);
  if (node->right)
    print_tree(stream, node->right, level + 1);
}

Node *rand_tree(Node_Pool *np, size_t level) {
  if (level == 0) {
    return NULL;
  }
  Node *root = node_pool_alloc_with_text(np, fruits[rand() % fruits_count]);
  root->left = rand_tree(np, level - 1);
  root->right = rand_tree(np, level - 1);
  return root;
}

void save_node_pool_to_file(Node_Pool *np, const char *file_path) {
  FILE *out = fopen(file_path, "wb");
  if (out == NULL) {
    exit(1);
  }
  size_t n = fwrite(np->nodes, sizeof(Node), np->sz, out);
  assert(n == np->sz);
  if (ferror(out)) {
    fprintf(stderr, "ERROR: could not write to file %s: %s\n", file_path, strerror(errno));
    exit(1);
  }
  fclose(out);
}

void load_node_pool_from_file(Node_Pool *np, const char *file_path) {
  FILE *out = fopen(file_path, "rb");
  if (out == NULL) {
    fprintf(stderr, "ERROR: could not read from file %s: %s\n", file_path, strerror(errno));
    exit(1);
  }
  fseek(out, 0, SEEK_END);
  long m = ftell(out);
  fseek(out, 0, SEEK_SET);
  assert(m % sizeof(Node) == 0);
  np->sz = m / sizeof(Node);
  assert(np->sz > NODE_POOL_CAP);

  size_t n = fread(np->nodes, sizeof(Node), np->sz, out);
  assert(n == np->sz);
  if (ferror(out)) {
    fprintf(stderr, "ERROR: could not write to file %s: %s\n", file_path, strerror(errno));
    exit(1);
  }
  fclose(out);
}

#define FRUITS_BIN_PATH "friute.bin"


int main() {

  srand(time(0));
  // for (size_t i = 0; i < 10; ++i) {
  //   printf("%s\n", fruits[rand() % fruits_count]);
  // }

  //Node *root = node_pool_alloc_with_text(&global_node_pool, "hello");
  //root->left = node_pool_alloc_with_text(&global_node_pool, "foo");
  //root->right = node_pool_alloc_with_text(&global_node_pool, "bar");

  Node *root = rand_tree(&global_node_pool, 5);
  print_tree(stdout, root, 0);
  save_node_pool_to_file(&global_node_pool, "friute.bin");

  load_node_pool_from_file(&global_node_pool, FRUITS_BIN_PATH);
  root = &global_node_pool.nodes[0];
  print_tree(stdout, root, 0);

  return 0;
}
