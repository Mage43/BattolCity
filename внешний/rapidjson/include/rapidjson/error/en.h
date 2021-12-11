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
        case kParseErrorNone:                           return RAPIDJSON_ERROR_STRING("������� ������.");

        case kParseErrorDocumentEmpty:                  return RAPIDJSON_ERROR_STRING("�������� ����.");
        case kParseErrorDocumentRootNotSingular:        return RAPIDJSON_ERROR_STRING("�� ������ ��������� �� ������ ��������� ������ ��������.");
    
        case kParseErrorValueInvalid:                   return RAPIDJSON_ERROR_STRING("������������ ��������.");
    
        case kParseErrorObjectMissName:                 return RAPIDJSON_ERROR_STRING("����������� ��� ��� �������� �������.");
        case kParseErrorObjectMissColon:                return RAPIDJSON_ERROR_STRING("����������� ��������� ����� ����� �������� �������.");
        case kParseErrorObjectMissCommaOrCurlyBracket:  return RAPIDJSON_ERROR_STRING("����������� ������� ��� '}' ����� �������� �������.");
    
        case kParseErrorArrayMissCommaOrSquareBracket:  return RAPIDJSON_ERROR_STRING("����������� ������� ��� ']'(���'{}' ����� � ������)����� �������� �������.");

        case kParseErrorStringUnicodeEscapeInvalidHex:  return RAPIDJSON_ERROR_STRING("������������ ����������������� ����� ����� \\u ������������� � ������.");
        case kParseErrorStringUnicodeSurrogateInvalid:  return RAPIDJSON_ERROR_STRING("����������� ���� � ������ �����������.");
        case kParseErrorStringEscapeInvalid:            return RAPIDJSON_ERROR_STRING("������������ escape-������ � ������.");
        case kParseErrorStringMissQuotationMark:        return RAPIDJSON_ERROR_STRING("����������� ����������� ������� � ������.");
        case kParseErrorStringInvalidEncoding:          return RAPIDJSON_ERROR_STRING("������������ ��������� � ������.");

        case kParseErrorNumberTooBig:                   return RAPIDJSON_ERROR_STRING("����� ������� ������, ����� ��� ����� ���� ������� � ������� �������.");
        case kParseErrorNumberMissFraction:             return RAPIDJSON_ERROR_STRING("���������� ����� ����� � �����.");
        case kParseErrorNumberMissExponent:             return RAPIDJSON_ERROR_STRING("���������� ���������� �����.");

        case kParseErrorTermination:                    return RAPIDJSON_ERROR_STRING("��������� �������������� ������ ��-�� ������ �����������.");
        case kParseErrorUnspecificSyntaxError:          return RAPIDJSON_ERROR_STRING("��������������� �������������� ������.");

        default:                                        return RAPIDJSON_ERROR_STRING("����������� ������.");
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
        case kValidateErrors:                           return RAPIDJSON_ERROR_STRING("��������� ���� ��� ��������� ������ ��������");
        case kValidateErrorNone:                        return RAPIDJSON_ERROR_STRING("������� ������.");

        case kValidateErrorMultipleOf:                  return RAPIDJSON_ERROR_STRING("����� '%�����������' �� ������ '��������' �������� '%���������'.");
        case kValidateErrorMaximum:                     return RAPIDJSON_ERROR_STRING("����� '%�����������' ������, ��� '������������' �������� '%���������'.");
        case kValidateErrorExclusiveMaximum:            return RAPIDJSON_ERROR_STRING("����� '%�����������' ������ ��� ����� '��������������� �������������' �������� '%���������'.");
        case kValidateErrorMinimum:                     return RAPIDJSON_ERROR_STRING("����� '%�����������' ������, ��� '�����������' �������� '%���������'.");
        case kValidateErrorExclusiveMinimum:            return RAPIDJSON_ERROR_STRING("����� '%�����������' ������ ��� ����� '��������������� ������������' �������� '%���������'.");

        case kValidateErrorMaxLength:                   return RAPIDJSON_ERROR_STRING("������ '%�����������' ������� �������� '������������ �����' '%���������'");
        case kValidateErrorMinLength:                   return RAPIDJSON_ERROR_STRING("������ '%�����������' ������, ��� �������� '����������� �����' '%���������'.");
        case kValidateErrorPattern:                     return RAPIDJSON_ERROR_STRING("������ '%�����������' �� ������������� ����������� ��������� '������'.");

        case kValidateErrorMaxItems:                    return RAPIDJSON_ERROR_STRING("������ ����� '%�����������' �������, ��� �������� 'maxItems' '%���������'.");
        case kValidateErrorMinItems:                    return RAPIDJSON_ERROR_STRING("������ ����� '%�����������' ������, ��� �������� 'minItems' '%���������'.");
        case kValidateErrorUniqueItems:                 return RAPIDJSON_ERROR_STRING("������ �������� ������������� �������� � ��������� '%����������', �� '���������� ��������' �����.");
        case kValidateErrorAdditionalItems:             return RAPIDJSON_ERROR_STRING("� ������� ���� �������������� ������� � �������� '%���������', ������� �� �������� ������.");

        case kValidateErrorMaxProperties:               return RAPIDJSON_ERROR_STRING("������ ����� '%�����������' ������, ��� ������, ��� '������������ �������� �������' '%���������'.");
        case kValidateErrorMinProperties:               return RAPIDJSON_ERROR_STRING("������ ����� '%�����������' ������, ��� ������, ��� '����������� �������� �������' '%���������'.");
        case kValidateErrorRequired:                    return RAPIDJSON_ERROR_STRING("� ������� ����������� ��������� ��������, ��������� ������: '%�����������'.");
        case kValidateErrorAdditionalProperties:        return RAPIDJSON_ERROR_STRING("������ ����� �������������� ������� '%��������', ������� �� �������� ������.");
        case kValidateErrorPatternProperties:           return RAPIDJSON_ERROR_STRING("������ ����� '�������� �������', ������� �� ��������� ������.");
        case kValidateErrorDependencies:                return RAPIDJSON_ERROR_STRING("� ������� ����������� �������� ��� ����������� �����, ��. ��������� ������.");

        case kValidateErrorEnum:                        return RAPIDJSON_ERROR_STRING("�������� ����� ��������, ������� �� �������� ����� �� ��� ���������� ������������� ��������.");
        case kValidateErrorType:                        return RAPIDJSON_ERROR_STRING("�������� ����� ��� '%�����������', �������� ��� � ��������� ������: '%���������'.");

        case kValidateErrorOneOf:                       return RAPIDJSON_ERROR_STRING("�������� �� ������������� �� ����� �� �������, ��������� � '����� ��', ��. ��������� ������.");
        case kValidateErrorOneOfMatch:                  return RAPIDJSON_ERROR_STRING("�������� ��������������� ���������� ���������, ��������� � '����� ��'.");
        case kValidateErrorAllOf:                       return RAPIDJSON_ERROR_STRING("�������� �� ������������� ���� ��������� ������, ��������� � ��������� '���', ��. ��������� ������.");
        case kValidateErrorAnyOf:                       return RAPIDJSON_ERROR_STRING("�������� �� ������������� �� ����� �� �������, ��������� � '����� ��', ��. ��������� ������.");
        case kValidateErrorNot:                         return RAPIDJSON_ERROR_STRING("�������� ��������������� ��������, ��������� '��'.");

        default:                                        return RAPIDJSON_ERROR_STRING("����������� ������.");
    }
}

RAPIDJSON_NAMESPACE_END

#ifdef __clang__
RAPIDJSON_DIAG_POP
#endif

#endif // RAPIDJSON_ERROR_EN_H_
