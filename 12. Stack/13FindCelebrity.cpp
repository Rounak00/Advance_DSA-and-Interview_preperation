
    int findCelebrity(int n)
    {

        stack<int> s;

        for (int i = 0; i < n; i++)
        {

            s.push(i);
        }

        while (s.size() > 1)
        {

            int a = s.top();
            s.pop();

            int b = s.top();

            s.pop();

            if (knows(a, b))
            {

                s.push(b);
            }
            else
            {

                s.push(a);
            }
        }
        int c = s.top();

        if (s.empty())
        {
            return -1;
        }
        for (int i = 0; i < n; i++)
        {

            if (i != c && !knows(i, c))
            {

                return -1;
            }
        }
        for (int i = 0; i < n; i++)
        {

            if (knows(c, i))
            {

                return -1;
            }
        }
        return c;
    }
