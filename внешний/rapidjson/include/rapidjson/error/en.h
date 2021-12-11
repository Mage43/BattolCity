// Tencent is pleased to support the open source community by making RapidJSON available.
// 
// Copyright (C) 2015 THL A29 Limited, a Tencent company, and Milo Yip.
//
// Licensed under the MIT License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// http://opensource.org/licenses/MIT
//
// Unless required by applicable law or agreed to in writing, software distributed 
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR 
// CONDITIONS OF ANY KIND, either express or implied. See the License for the 
// specific language governing permissions and limitations under the License.

#ifndef RAPIDJSON_ERROR_EN_H_
#define RAPIDJSON_ERROR_EN_H_

#include "error.h"

#ifdef __clang__
RAPIDJSON_DIAG_PUSH
RAPIDJSON_DIAG_OFF(switch-enum)
RAPIDJSON_DIAG_OFF(covered-switch-default)
#endif

RAPIDJSON_NAMESPACE_BEGIN

//! Maps error code of parsing into error message.
/*!
    \ingroup RAPIDJSON_ERRORS
    \param parseErrorCode Error code obtained in parsing.
    \return the error message.
    \note User can make a copy of this function for localization.
        Using switch-case is safer for future modification of error codes.
*/
inline const RAPIDJSON_ERROR_CHARTYPE* GetParseError_En(ParseErrorCode parseErrorCode) {
    switch (parseErrorCode) {
        case kParseErrorNone:                           return RAPIDJSON_ERROR_STRING("Никакой ошибки.");

        case kParseErrorDocumentEmpty:                  return RAPIDJSON_ERROR_STRING("Документ пуст.");
        case kParseErrorDocumentRootNotSingular:        return RAPIDJSON_ERROR_STRING("За корнем документа не должны следовать другие значения.");
    
        case kParseErrorValueInvalid:                   return RAPIDJSON_ERROR_STRING("Недопустимое значение.");
    
        case kParseErrorObjectMissName:                 return RAPIDJSON_ERROR_STRING("Отсутствует имя для элемента объекта.");
        case kParseErrorObjectMissColon:                return RAPIDJSON_ERROR_STRING("Отсутствует двоеточие после имени элемента объекта.");
        case kParseErrorObjectMissCommaOrCurlyBracket:  return RAPIDJSON_ERROR_STRING("Отсутствует запятая или '}' после элемента объекта.");
    
        case kParseErrorArrayMissCommaOrSquareBracket:  return RAPIDJSON_ERROR_STRING("Отсутствует запятая или ']'(или'{}' после и начало)после элемента массива.");

        case kParseErrorStringUnicodeEscapeInvalidHex:  return RAPIDJSON_ERROR_STRING("Неправильная шестнадцатеричная цифра после \\u экранирования в строке.");
        case kParseErrorStringUnicodeSurrogateInvalid:  return RAPIDJSON_ERROR_STRING("Суррогатная пара в строке недопустима.");
        case kParseErrorStringEscapeInvalid:            return RAPIDJSON_ERROR_STRING("Недопустимый escape-символ в строке.");
        case kParseErrorStringMissQuotationMark:        return RAPIDJSON_ERROR_STRING("Отсутствует закрывающая кавычка в строке.");
        case kParseErrorStringInvalidEncoding:          return RAPIDJSON_ERROR_STRING("Недопустимая кодировка в строке.");

        case kParseErrorNumberTooBig:                   return RAPIDJSON_ERROR_STRING("Число слишком велико, чтобы его можно было хранить в двойном размере.");
        case kParseErrorNumberMissFraction:             return RAPIDJSON_ERROR_STRING("Пропустите часть дроби в числе.");
        case kParseErrorNumberMissExponent:             return RAPIDJSON_ERROR_STRING("Пропустите показатель числа.");

        case kParseErrorTermination:                    return RAPIDJSON_ERROR_STRING("Завершите синтаксический анализ из-за ошибки обработчика.");
        case kParseErrorUnspecificSyntaxError:          return RAPIDJSON_ERROR_STRING("Неспецифическая синтаксическая ошибка.");

        default:                                        return RAPIDJSON_ERROR_STRING("Неизвестная ошибка.");
    }
}

//! Maps error code of validation into error message.
/*!
    \ingroup RAPIDJSON_ERRORS
    \param validateErrorCode Error code obtained from validator.
    \return the error message.
    \note User can make a copy of this function for localization.
        Using switch-case is safer for future modification of error codes.
*/
inline const RAPIDJSON_ERROR_CHARTYPE* GetValidateError_En(ValidateErrorCode validateErrorCode) {
    switch (validateErrorCode) {
        case kValidateErrors:                           return RAPIDJSON_ERROR_STRING("Произошла одна или несколько ошибок проверки");
        case kValidateErrorNone:                        return RAPIDJSON_ERROR_STRING("Никакой ошибки.");

        case kValidateErrorMultipleOf:                  return RAPIDJSON_ERROR_STRING("Число '%фактическое' не кратно 'кратному' значению '%ожидаемое'.");
        case kValidateErrorMaximum:                     return RAPIDJSON_ERROR_STRING("Число '%фактическое' больше, чем 'максимальное' значение '%ожидаемое'.");
        case kValidateErrorExclusiveMaximum:            return RAPIDJSON_ERROR_STRING("Число '%фактическое' больше или равно 'исключительному максимальному' значению '%ожидаемое'.");
        case kValidateErrorMinimum:                     return RAPIDJSON_ERROR_STRING("Число '%фактическое' меньше, чем 'минимальное' значение '%ожидаемое'.");
        case kValidateErrorExclusiveMinimum:            return RAPIDJSON_ERROR_STRING("Число '%фактическое' меньше или равно 'исключительному минимальному' значению '%ожидаемое'.");

        case kValidateErrorMaxLength:                   return RAPIDJSON_ERROR_STRING("Строка '%фактическая' длиннее значения 'максимальная длина' '%ожидаемая'");
        case kValidateErrorMinLength:                   return RAPIDJSON_ERROR_STRING("Строка '%фактическая' короче, чем значение 'минимальной длины' '%ожидаемое'.");
        case kValidateErrorPattern:                     return RAPIDJSON_ERROR_STRING("Строка '%фактический' не соответствует регулярному выражению 'шаблон'.");

        case kValidateErrorMaxItems:                    return RAPIDJSON_ERROR_STRING("Массив длины '%фактический' длиннее, чем значение 'maxItems' '%ожидаемый'.");
        case kValidateErrorMinItems:                    return RAPIDJSON_ERROR_STRING("Массив длины '%фактический' короче, чем значение 'minItems' '%ожидаемый'.");
        case kValidateErrorUniqueItems:                 return RAPIDJSON_ERROR_STRING("Массив содержит повторяющиеся элементы с индексами '%дубликатов', но 'Уникальные элементы' верны.");
        case kValidateErrorAdditionalItems:             return RAPIDJSON_ERROR_STRING("В массиве есть дополнительный элемент с индексом '%запрещено', который не разрешен схемой.");

        case kValidateErrorMaxProperties:               return RAPIDJSON_ERROR_STRING("Объект имеет '%фактических' членов, что больше, чем 'максимальное значение свойств' '%ожидаемое'.");
        case kValidateErrorMinProperties:               return RAPIDJSON_ERROR_STRING("Объект имеет '%фактических' членов, что меньше, чем 'минимальное значение свойств' '%ожидаемое'.");
        case kValidateErrorRequired:                    return RAPIDJSON_ERROR_STRING("В объекте отсутствуют следующие элементы, требуемые схемой: '%отсутствует'.");
        case kValidateErrorAdditionalProperties:        return RAPIDJSON_ERROR_STRING("Объект имеет дополнительный элемент '%запрещен', который не разрешен схемой.");
        case kValidateErrorPatternProperties:           return RAPIDJSON_ERROR_STRING("Объект имеет 'свойства шаблона', которые не разрешены схемой.");
        case kValidateErrorDependencies:                return RAPIDJSON_ERROR_STRING("У объекта отсутствуют свойства или зависимости схемы, см. Следующие ошибки.");

        case kValidateErrorEnum:                        return RAPIDJSON_ERROR_STRING("Свойство имеет значение, которое не является одним из его допустимых перечисленных значений.");
        case kValidateErrorType:                        return RAPIDJSON_ERROR_STRING("Свойство имеет тип '%фактический', которого нет в следующем списке: '%ожидаемый'.");

        case kValidateErrorOneOf:                       return RAPIDJSON_ERROR_STRING("Свойство не соответствует ни одной из подсхем, указанных в 'одной из', см. Следующие ошибки.");
        case kValidateErrorOneOfMatch:                  return RAPIDJSON_ERROR_STRING("Свойство соответствовало нескольким подсхемам, указанным в 'одной из'.");
        case kValidateErrorAllOf:                       return RAPIDJSON_ERROR_STRING("Свойство не соответствует всем вложенным схемам, указанным в параметре 'все', см. Следующие ошибки.");
        case kValidateErrorAnyOf:                       return RAPIDJSON_ERROR_STRING("Свойство не соответствует ни одной из подсхем, указанных в 'любой из', см. Следующие ошибки.");
        case kValidateErrorNot:                         return RAPIDJSON_ERROR_STRING("Свойство соответствовало подсхеме, указанной 'не'.");

        default:                                        return RAPIDJSON_ERROR_STRING("Неизвестная ошибка.");
    }
}

RAPIDJSON_NAMESPACE_END

#ifdef __clang__
RAPIDJSON_DIAG_POP
#endif

#endif // RAPIDJSON_ERROR_EN_H_
