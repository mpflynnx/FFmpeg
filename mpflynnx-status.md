## lesson1 compile errors

```bash
$ make tests/checkasm/checkasm
LD	tests/checkasm/checkasm
/usr/bin/ld: tests/checkasm/checkasm.o:(.rodata+0x378): undefined reference to `checkasm_check_lesson1'
/usr/bin/ld: tests/checkasm/example.o: in function `checkasm_check_example':
/run/media/live/ntfs/youtube-learning/ffmpeg/my-forked-repo/FFmpeg/tests/checkasm/example.c:19: undefined reference to `ff_add_bytes_c'
/usr/bin/ld: /run/media/live/ntfs/youtube-learning/ffmpeg/my-forked-repo/FFmpeg/tests/checkasm/example.c:36: undefined reference to `ff_add_bytes_c'
collect2: error: ld returned 1 exit status
make: *** [tests/checkasm/Makefile:128: tests/checkasm/checkasm] Error 1
```
- Current commit error

```bash
$ make tests/checkasm/checkasm
LD	tests/checkasm/checkasm
/usr/bin/ld: tests/checkasm/lesson1.o: in function `checkasm_check_lesson1':
/run/media/live/ntfs/youtube-learning/ffmpeg/my-forked-repo/FFmpeg/tests/checkasm/lesson1.c:57: undefined reference to `ff_add_values_sse2'
collect2: error: ld returned 1 exit status
make: *** [tests/checkasm/Makefile:128: tests/checkasm/checkasm] Error 1
```
