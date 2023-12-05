void MainWindow::parse(QString exp)
{
    int firstIndex = exp.indexOf("!", 0);

    QRegularExpression reg("\\d*.\\d*!");
    QRegularExpressionMatchIterator iter =  reg.globalMatch(exp);
    while(iter.hasNext())
    {
        QString temp = iter.next().captured(0);
        QString temp1 = temp;
        exp.replace(temp1, calculateFactorial(temp));
    }

    QString temp;
    std::stack<QChar> _stack;

    if(exp[firstIndex - 1] == ')')
    {
        // temp.append(")");
        for(int ii = firstIndex - 1; ii >= 0; ii--)
        {
            qDebug() << exp[ii];
            temp = exp[ii] + temp;
            if(exp[ii] == ')')
            {
                _stack.push(')');
            }
            else if(exp[ii] == '(')
            {
                _stack.pop();
            }
            if(_stack.empty())
            {
                while(exp[--ii].isLetter())
                {
                    temp = exp[ii] + temp;
                }

                qDebug() << temp;
                exp.replace(temp+"!", calculateFactorial(temp));
                temp.clear();
                ii = exp.indexOf("!", firstIndex);
                if(ii == -1)
                {
                    break;
                }
            }
        }
    }

    ui->lineEdit_2->setText(exp);
}
