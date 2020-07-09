#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>

int main(int argc, char** argv) {
	av_register_all();
	AVFormatContext *pFormatCtx = NULL;
	// Open video file
	if(avformat_open_input(&pFormatCtx, argv[1], NULL, NULL) != 0) {
		return -1;
	}
	if(avformat_find_stream_info())
}