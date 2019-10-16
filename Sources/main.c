//
// Created by Valentin on 10/15/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "../Header/core_sr_desktop.h"

int main(void)
{
	struct SoundIo *soundio = soundio_create();
	struct SoundIoDevice *selected = NULL;

	int default_device;

	soundio_connect(soundio);
	soundio_flush_events(soundio);
	default_device = soundio_default_output_device_index(soundio);
	selected = soundio_get_output_device(soundio, default_device);
	soundio_device_sort_channel_layouts(selected);
	return 0;
}