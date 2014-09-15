#include <unistd.h>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <string.h>
#include "Husky/ThreadPoolServer.hpp"
#include "KeywordExtractor.hpp"

using namespace Husky;
using namespace CppJieba;

const size_t PORT = 11201;
const size_t THREAD_NUMBER = 4;
const size_t QUEUE_MAX_SIZE = 256;
const char* const DICT_PATH = "./dict/dict.utf8";
const char* const MODEL_PATH = "./dict/hmm_model.utf8";
const char* const IDF_PATH = "./dict/idf.utf8";
const char* const STOP_WORDS_PATH = "./dict/stop_words.utf8";
const size_t TOP_N = 5;

class ReqHandler: public IRequestHandler
{
    public:
        ReqHandler(const string& dictPath, const string& modelPath, const string& idfPath, const string& stopwordsPath): _keyword(dictPath, modelPath, idfPath, stopwordsPath){};
        virtual ~ReqHandler(){};
    public:
        virtual bool do_GET(const HttpReqInfo& httpReq, string& strSnd) const
        {
            vector<pair<string, double> > words;
            string sentence, tmp;
            httpReq.GET("sentence", tmp);
            URLDecode(tmp, sentence);
            _keyword.extract(sentence, words, TOP_N);
            join(words.begin(), words.end(), strSnd, " ");
            return true;
        }
        virtual bool do_POST(const HttpReqInfo& httpReq, string& strSnd) const
        {
            return false; 
        }
    private:
        KeywordExtractor _keyword;
};

int main(int argc, char* argv[])
{
    ReqHandler reqHandler(DICT_PATH, MODEL_PATH, IDF_PATH, STOP_WORDS_PATH);
    ThreadPoolServer server(THREAD_NUMBER, QUEUE_MAX_SIZE, PORT, reqHandler);
    server.start();
    return EXIT_SUCCESS;
}

