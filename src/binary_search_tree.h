struct node {
  struct node *left;
  int data;
  struct node *right;
};

int is_empty(struct node *tree);
struct node *insert_node(int data, struct node *tree);
