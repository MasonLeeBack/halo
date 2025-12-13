/*
FILES.C
*/

/* ---------- headers */

#include "cseries.h"
#include "cseries_windows.h"
#include "files.h"

/* ---------- constants */

/* ---------- macros */

/* ---------- structures */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- public code */

void file_location_set_volume(
	short location,
	const char *volume_name)
{
	match_assert("c:\\halo\\SOURCE\\tag_files\\files.c", 75, location>0 && location<NUMBER_OF_FILE_REFERENCE_LOCATIONS);
	match_assert("c:\\halo\\SOURCE\\tag_files\\files.c", 76, strlen(file_location_volume_names[location])==0);
	match_assert("c:\\halo\\SOURCE\\tag_files\\files.c", 77, strlen(volume_name)<=MAXIMUM_FILENAME_LENGTH);

	strncpy(file_location_volume_names[location], volume_name, NUMBEROF(*file_location_volume_names)-1);
	file_location_volume_names[location][NUMBEROF(*file_location_volume_names)-1]= '\0';

	return;
}

struct file_reference *file_reference_create(
	struct file_reference *reference,
	short location)
{
	struct file_reference_info *info = (struct file_reference_info *)reference;
    match_assert("c:\\halo\\SOURCE\\tag_files\\files.c", 91, info);
	match_assert("c:\\halo\\SOURCE\\tag_files\\files.c", 92, location>=NONE && location<NUMBER_OF_FILE_REFERENCE_LOCATIONS);

	memset(info, 0, sizeof(*info));
	info->location= location;
	info->signature= FILE_REFERENCE_SIGNATURE;

	return reference;
}

/* ---------- private code */
