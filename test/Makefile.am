if BUILD_TESTS
AM_CPPFLAGS = -I$(top_srcdir)/src $(CHECK_CFLAGS) $(LIBEVDEV_CFLAGS)

TEST_LIBS = liblitest.la $(CHECK_LIBS) $(LIBUDEV_LIBS) $(LIBEVDEV_LIBS) $(top_builddir)/src/libinput.la -lm
noinst_LTLIBRARIES = liblitest.la
liblitest_la_SOURCES = \
	$(top_srcdir)/src/libinput-util.h \
	$(top_srcdir)/src/libinput-util.c \
	litest.h \
	litest-int.h \
	litest-bcm5974.c \
	litest-keyboard.c \
	litest-mouse.c \
	litest-synaptics.c \
	litest-trackpoint.c \
	litest-wacom-touch.c \
	litest.c

run_tests = test-udev test-path test-pointer test-touch
build_tests = test-build-linker test-build-pedantic-c99 test-build-std-gnuc90

noinst_PROGRAMS = $(build_tests) $(run_tests)
TESTS = $(run_tests)

test_udev_SOURCES = udev.c
test_udev_CFLAGS = $(AM_CPPFLAGS)
test_udev_LDADD = $(TEST_LIBS)
test_udev_LDFLAGS = -static

test_path_SOURCES = path.c
test_path_CFLAGS = $(AM_CPPFLAGS)
test_path_LDADD = $(TEST_LIBS)
test_path_LDFLAGS = -static

test_pointer_SOURCES = pointer.c
test_pointer_CFLAGS = $(AM_CPPFLAGS)
test_pointer_LDADD = $(TEST_LIBS)
test_pointer_LDFLAGS = -static

test_touch_SOURCES = touch.c
test_touch_CFLAGS = $(AM_CPPFLAGS)
test_touch_LDADD = $(TEST_LIBS)
test_touch_LDFLAGS = -static

# build-test only
test_build_pedantic_c99_SOURCES = build-pedantic.c
test_build_pedantic_c99_CFLAGS = $(AM_CPPFLAGS) -std=c99 -pedantic -Werror

test_build_std_gnuc90_SOURCES = build-pedantic.c
test_build_std_gnuc90_CFLAGS = $(AM_CPPFLAGS) -std=gnu90 -Werror

# test for linking with the minimal linker flags
test_build_linker_SOURCES = build-pedantic.c
test_build_linker_CFLAGS = -I$(top_srcdir)/src
test_build_linker_LDADD = $(top_builddir)/src/libinput.la

endif
