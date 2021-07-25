import os
import json

import argparse
import tempfile


def load_hash(content):
    hash = {}
    if content:
        hash = json.loads(content)

    return hash


def get_data(storage_name):
    storage_path = os.path.join(tempfile.gettempdir(), storage_name)
    file_exists = os.path.isfile(storage_path)

    if not file_exists:
        os.mknod(storage_path)

    with open(storage_path, 'r+') as json_file:
        content = json_file.read()
        hash = load_hash(content)

    return hash


def save_hash(storage_name, hash):
    storage_path = os.path.join(tempfile.gettempdir(), storage_name)

    with open(storage_path, 'w+') as f:
        f.write(json.dumps(hash))


def prepare_hash(args, hash):
    if not args.value:
        print(", ".join(hash.get(args.key, '')))
    else:
        if args.key in hash:
            hash[args.key].append(args.value)
        else:
            hash[args.key] = [args.value]

    return hash


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("--key", help='storage key')
    parser.add_argument("--value", help='set value by key')
    args = parser.parse_args()

    return args


if __name__ == '__main__':
    storage_name = 'storage.data'

    hash = get_data(storage_name)
    args = parse_args()

    hash = prepare_hash(args, hash)

    save_hash(storage_name, hash)
