TEMPLATE = subdirs

SUBDIRS += \
    CalcMathExpression \
    \
    RpnCalc #\
#    Matrices

CalcMathExpression.depends = RpnCalc
#CalcMathExpression.depends = Matrices
