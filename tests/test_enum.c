#include "../munit/munit.h"
#include "../src/enum.h"

static MunitResult test_color_defined(const MunitParameter params[],
                                      void *data) {
  (void)params;
  (void)data;

  munit_assert_int(RED, ==, 55);
  munit_assert_int(GREEN, ==, 176);
  munit_assert_int(BLUE, ==, 38);

  return MUNIT_OK;
}

static MunitResult test_color_defined_correctly(const MunitParameter params[],
                                                void *data) {
  (void)params;
  (void)data;

  munit_assert_int(RED, !=, 0);
  munit_assert_int(GREEN, !=, 120);
  munit_assert_int(BLUE, !=, 215);

  return MUNIT_OK;
}

static MunitResult test_switch_enum(const MunitParameter params[], void *data) {
  (void)params;
  (void)data;

  munit_assert_string_equal(http_to_str(HTTP_BAD_REQUEST), "400 Bad request");
  munit_assert_string_equal(http_to_str(HTTP_UNAUTHORIZED), "401 Unauthorized");
  munit_assert_string_equal(http_to_str(HTTP_NOT_FOUND), "404 Not found");
  munit_assert_string_equal(http_to_str(HTTP_TEAPOT), "418 I AM A TEAPOT!");
  munit_assert_string_equal(http_to_str(HTTP_INTERNAL_SERVER_ERROR),
                            "500 Interval Server Error");

  return MUNIT_OK;
}

static MunitTest tests[] = {
    {"/are_defined", test_color_defined, NULL, NULL, MUNIT_TEST_OPTION_NONE,
     NULL},

    {"/are_defined_correctly", test_color_defined_correctly, NULL, NULL,
     MUNIT_TEST_OPTION_NONE, NULL},

    {"/switch_enum", test_switch_enum, NULL, NULL, MUNIT_TEST_OPTION_NONE,
     NULL},

    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}};

static const MunitSuite suite = {(char *)"colors", tests, NULL, 1,
                                 MUNIT_SUITE_OPTION_NONE};

int main(int argc, char *argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}
