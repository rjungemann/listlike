#include "string.h"
#include "test.h"
#include "listlike.h"

void test_listlike_as_stack () {
  test_start("Listlike as stack");

  test_describe("An empty listlike");

  listlike *listlike = listlike_create();
  test_ok(listlike != NULL, "listlike is not null");
  test_ok(listlike->head == NULL, "listlike head is null");
  test_ok(listlike->tail == NULL, "listlike tail is null");
  test_ok(listlike_length(listlike) == 0, "listlike should be empty");

  test_describe("A listlike with one item");

  char *data1 = "Hello";
  listlike_push(listlike, data1);
  test_ok(listlike->head != NULL, "listlike head is not null");
  test_ok(listlike->tail != NULL, "listlike tail is not null");
  test_ok(listlike_length(listlike) == 1, "listlike should have one item");
  test_ok(listlike->head == listlike->tail, "listlike head == listlike tail");
  test_ok(listlike->tail->previous == NULL, "The element's previous is null");
  test_ok(listlike->tail->next == NULL, "The element's next is null");
  test_ok(listlike->tail->data != NULL, "The element's data is not null");
  test_ok(listlike->tail->data == data1, "The element's data is equal to what was pushed in");

  test_describe("A listlike with two items");

  char *data2 = "world";
  listlike_push(listlike, data2);
  test_ok(listlike->head != NULL, "listlike head is not null");
  test_ok(listlike->tail != NULL, "listlike tail is not null");
  test_ok(listlike_length(listlike) == 2, "listlike should have two items");
  test_ok(listlike->head != listlike->tail, "listlike head != listlike tail");

  test_describe("A two-item listlike popped once");

  char *new_data_1 = (char *) listlike_pop(listlike);
  test_ok(listlike_length(listlike) == 1, "listlike should have a length of 1");
  test_ok(new_data_1 != NULL, "Popped data should not be null");
  test_ok(strcmp(new_data_1, "world") == 0, "Popped data should be correct");

  test_describe("A two-item listlike popped twice");

  char *new_data_2 = (char *) listlike_pop(listlike);
  test_ok(listlike_length(listlike) == 0, "listlike should have a length of 0");
  test_ok(new_data_2 != NULL, "Popped data should not be null");
  test_ok(strcmp(new_data_2, "Hello") == 0, "Popped data should be correct");

  test_describe("A two-item listlike popped three times");

  char *new_data_3 = (char *) listlike_pop(listlike);
  test_ok(listlike_length(listlike) == 0, "listlike should have a length of 0");
  test_ok(new_data_3 == NULL, "Popped data should be null");

  test_end();
}

void test_listlike_as_queue () {
  test_start("Listlike as queue");

  listlike *listlike = listlike_create();

  char *data1 = "Hello";
  listlike_push(listlike, data1);

  char *data2 = "world";
  listlike_push(listlike, data2);

  test_describe("A two-item queue shifted once");

  char *new_data_1 = (char *) listlike_shift(listlike);
  test_ok(listlike_length(listlike) == 1, "Queue should have a length of 1");
  test_ok(new_data_1 != NULL, "Shifted data should not be null");
  test_ok(strcmp(new_data_1, "Hello") == 0, "Shifted data should be correct");

  test_describe("A two-item listlike shifted twice");

  char *new_data_2 = (char *) listlike_pop(listlike);
  test_ok(listlike_length(listlike) == 0, "Queue should have a length of 0");
  test_ok(new_data_2 != NULL, "Shifted data should not be null");
  test_ok(strcmp(new_data_2, "world") == 0, "Shifted data should be correct");

  test_describe("A two-item listlike shifted three times");

  char *new_data_3 = (char *) listlike_pop(listlike);
  test_ok(listlike_length(listlike) == 0, "Queue should have a length of 0");
  test_ok(new_data_3 == NULL, "Shifted data should be null");

  test_end();
}

int main (__attribute__((unused)) int argc, __attribute__((unused)) char **argv) {
  test_listlike_as_stack();
  test_listlike_as_queue();
}
