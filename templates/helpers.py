from re import Match
from re import sub


def replacement(match: Match) -> str:
    return match.group(0)[0] + '_' + match.group(0)[1]


def to_header_format(string: str) -> str:
    return sub(r'[a-z][A-Z]', replacement, string).upper()
