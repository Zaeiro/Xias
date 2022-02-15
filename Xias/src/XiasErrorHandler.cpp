#include "XiasErrorHandler.h"

#include "NoViableAltException.h"
#include "misc/IntervalSet.h"
#include "atn/ParserATNSimulator.h"
#include "InputMismatchException.h"
#include "FailedPredicateException.h"
#include "ParserRuleContext.h"
#include "atn/RuleTransition.h"
#include "atn/ATN.h"
#include "atn/ATNState.h"
#include "Parser.h"
#include "CommonToken.h"
#include "Vocabulary.h"
#include "support/StringUtils.h"

using namespace antlr4;
using namespace antlrcpp;

void XiasErrorHandler::reportError(Parser* recognizer, const RecognitionException& e)
{
	// If we've already reported an error and have not matched a token
	// yet successfully, don't report any errors.
	if (inErrorRecoveryMode(recognizer)) {
		return; // don't report spurious errors
	}
	
	beginErrorCondition(recognizer);
	if (is<const NoViableAltException *>(&e)) {
		reportNoViableAlternative(recognizer, static_cast<const NoViableAltException &>(e));
	} else if (is<const InputMismatchException *>(&e)) {
		reportInputMismatch(recognizer, static_cast<const InputMismatchException &>(e));
	} else if (is<const FailedPredicateException *>(&e)) {
		reportFailedPredicate(recognizer, static_cast<const FailedPredicateException &>(e));
	} else if (is<const RecognitionException *>(&e)) {
		recognizer->notifyErrorListeners(e.getOffendingToken(), e.what(), std::current_exception());
	}
}
