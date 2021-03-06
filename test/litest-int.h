/*
 * Copyright © 2013 Red Hat, Inc.
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that copyright
 * notice and this permission notice appear in supporting documentation, and
 * that the name of the copyright holders not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no representations
 * about the suitability of this software for any purpose.  It is provided "as
 * is" without express or implied warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
 */

#if HAVE_CONFIG_H
#include "config.h"
#endif

#ifndef LITEST_INT_H
#define LITEST_INT_H
#include "litest.h"

struct litest_test_device {
       enum litest_device_type type;
       enum litest_device_feature features;
       const char *shortname;
       void (*setup)(void); /* test fixture, used by check */
       void (*teardown)(void); /* test fixture, used by check */

       void (*create)(struct litest_device *d);
};

struct litest_device_interface {
	void (*touch_down)(struct litest_device *d, unsigned int slot, int x, int y);
	void (*touch_move)(struct litest_device *d, unsigned int slot, int x, int y);

	int min[2];
	int max[2];
};

void litest_set_current_device(struct litest_device *device);
int litest_scale(const struct litest_device *d, unsigned int axis, int val);
void litest_generic_device_teardown(void);

#endif
