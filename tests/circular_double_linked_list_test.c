#include<stdarg.h>
#include<stddef.h>
#include<setjmp.h>
#include<cmocka.h>
#include<stdlib.h>
#include "circular_double_linked_list.h"

static void create_list_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_list(5, list);
  assert_int_equal(list->data, 5);
  assert_non_null(list->prev);
  assert_non_null(list->next);
}

static void insert_end_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_list(5, list);
  list = insert_end(10, list);
  assert_int_equal(list->data, 5);
  assert_int_equal(list->prev->data, 10);
  assert_int_equal(list->next->data, 10);
  assert_int_equal(list->next->prev->data, 5);
  assert_int_equal(list->next->next->data, 5);
}

static void insert_begin_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_list(5, list);
  list = insert_begin(10, list);
  assert_int_equal(list->data, 10);
  assert_int_equal(list->prev->data, 5);
  assert_int_equal(list->next->data, 5);
  assert_int_equal(list->next->next->data, 10);
}

static void insert_after_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_list(5, list);
  list = insert_end(10, list);
  list = insert_after(5, 7, list);
  assert_int_equal(list->data, 5);
  assert_int_equal(list->prev->data, 10);
  assert_int_equal(list->next->data, 7);
}

static void insert_before_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_list(5, list);
  list = insert_end(10, list);
  list = insert_before(10, 7, list);
  assert_int_equal(list->data, 5);
  assert_int_equal(list->prev->data, 10);
  assert_int_equal(list->next->data, 7);
}

static void delete_node_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_list(5, list);
  list = insert_end(10, list);
  list = delete_node(5, list);
  assert_int_equal(list->data, 10);
  assert_int_equal(list->next->data, 10);
}

static void delete_middle_node_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_list(5, list);
  list = insert_end(10, list);
  list = insert_end(12, list);
  list = delete_node(10, list);
  assert_int_equal(list->data, 5);
  assert_int_equal(list->next->data, 12);
  assert_int_equal(list->next->next->data, 5);
}

static void delete_end_node_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_list(5, list);
  list = insert_end(10, list);
  list = insert_end(12, list);
  list = delete_node(12, list);
  assert_int_equal(list->data, 5);
  assert_int_equal(list->next->data, 10);
  assert_int_equal(list->next->next->data, 5);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(create_list_test),
    cmocka_unit_test(insert_end_test),
    cmocka_unit_test(insert_begin_test),
    cmocka_unit_test(insert_after_test),
    cmocka_unit_test(insert_before_test),
   // cmocka_unit_test(delete_node_test),
    //cmocka_unit_test(delete_middle_node_test),
  //  cmocka_unit_test(delete_end_node_test),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
