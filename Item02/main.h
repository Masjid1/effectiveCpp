class GamePlayer
{
private:
    /// ����static integer class consts�����Խ�������������䣬�������塣
    static const int NumTurns = 5;
    /// warning: ISO C++ forbids zero-size array 'score' [-Wpedantic]|
    int score[NumTurns];
};


class GamePlayer2
{
private:
    /// ����static integral class consts type��Ҳ������ͷ�ļ���д������������䣬��Դ�ļ��������塣
    static const int NumTurns;
    /// warning: ISO C++ forbids zero-size array 'score' [-Wpedantic]|
//    int score[NumTurns];
};


class GamePlayer3
{
private:
    /// ����һ���������
    /// ����Pi��non-integral type�ģ����Ա���Ҫ�ж��塣
    /// ʵ���ļ��б������һ��������䣬�磺const double GamePlayer3::Pi = 3.141592654;
    static const double Pi;
    enum { NumTurns = 5 };  /// "the nume hack", ��NumTurns��Ϊ5��һ���Ǻ�����
    int score[NumTurns];
};
