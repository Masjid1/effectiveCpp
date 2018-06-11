class GamePlayer
{
private:
    /// 对于static integer class consts，可以仅有如下声明语句，而不定义。
    static const int NumTurns = 5;
    /// warning: ISO C++ forbids zero-size array 'score' [-Wpedantic]|
    int score[NumTurns];
};


class GamePlayer2
{
private:
    /// 对于static integral class consts type，也可以在头文件中写有如下声明语句，在源文件中做定义。
    static const int NumTurns;
    /// warning: ISO C++ forbids zero-size array 'score' [-Wpedantic]|
//    int score[NumTurns];
};


class GamePlayer3
{
private:
    /// 这是一条声明语句
    /// 由于Pi是non-integral type的，所以必须要有定义。
    /// 实现文件中必须包含一条定义语句，如：const double GamePlayer3::Pi = 3.141592654;
    static const double Pi;
    enum { NumTurns = 5 };  /// "the nume hack", 令NumTurns成为5的一个记号名称
    int score[NumTurns];
};
