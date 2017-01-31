#ifndef LISTLIKE_H
#define LISTLIKE_H

#include "stdlib.h"

typedef struct listlike_t {
  struct element_t *head;
  struct element_t *tail;
  size_t length;
} listlike;

typedef struct element_t {
  struct element_t *previous;
  struct element_t *next;
  void *data;
} element;

listlike *listlike_create () {
  listlike *list = (listlike *) malloc(sizeof(listlike));
  list->head = NULL;
  list->tail = NULL;
  list->length = 0;
  return list;
}

size_t listlike_length (listlike *listlike) {
  return listlike->length;
}

void listlike_push (listlike *list, void *data) {
  element *el = (element *) malloc(sizeof(element));
  el->previous = NULL;
  el->next = NULL;
  el->data = data;

  if (listlike_length(list) == 0) {
    list->head = el;
    list->tail = el;
    (list->length)++;
    return;
  }

  element *old_head = list->head;
  old_head->previous = NULL;
  el->next = old_head;
  list->head = el;
  (list->length)++;
  return;
}

void *listlike_pop (listlike *list) {
  if (listlike_length(list) == 0) {
    return NULL;
  }

  element *el = list->head;
  if (list->tail == el) {
    list->tail = NULL;
  }

  element *next = el->next;
  void *data = el->data;

  // TODO: Move this.
  el->previous = NULL;
  el->next = NULL;
  el->data = NULL;
  free(el);

  if (next != NULL) {
    next->previous = NULL;
    list->head = next;
  }

  (list->length)--;

  return data;
}

// TODO: Test this.
void *listlike_peek (listlike *listlike) {
  if (listlike->head == NULL) {
    return NULL;
  }

  return listlike->head->data;
}

void *listlike_shift (listlike *list) {
  if (listlike_length(list) == 0) {
    return NULL;
  }

  element *el = list->tail;
  if (list->head == el) {
    list->head = NULL;
  }

  element *previous = el->previous;
  void *data = el->data;

  // TODO: Move this.
  el->previous = NULL;
  el->next = NULL;
  el->data = NULL;
  free(el);

  if (previous != NULL) {
    previous->next = NULL;
    list->tail = previous;
  }

  (list->length)--;

  return data;
}

#endif
