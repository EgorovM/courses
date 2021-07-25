import os.path
import csv


class CarBase:
    def __init__(self, brand, photo_file_name, carrying):
        self.brand = brand
        self.photo_file_name = photo_file_name
        self.carrying = float(carrying)

    def get_photo_file_ext(self):
        return os.path.splitext(self.photo_file_name)[1]


class Car(CarBase):
    def __init__(self, brand, photo_file_name, carrying, passenger_seats_count):
        super().__init__(brand, photo_file_name, carrying)
        self.car_type = 'car'
        self.passenger_seats_count = int(passenger_seats_count)


class Truck(CarBase):
    def __init__(self, brand, photo_file_name, carrying, body_whl):
        super().__init__(brand, photo_file_name, carrying)
        self.car_type = 'truck'

        whl = body_whl.split('x')

        try:
            l, w, h = whl
            self.body_length = float(l)
            self.body_width = float(w)
            self.body_height = float(h)
        except ValueError:
            self.body_length = 0.0
            self.body_width = 0.0
            self.body_height = 0.0

    def get_body_volume(self):
        return self.body_width * self.body_height * self.body_length


class SpecMachine(CarBase):
    def __init__(self, brand, photo_file_name, carrying, extra):
        super().__init__(brand, photo_file_name, carrying)
        self.car_type = 'spec_machine'
        self.extra = extra


def get_dict_from_csv(csv_filename):
    labels = ['car_type', 'brand', 'passenger_seats_count',
              'photo_file_name', 'body_whl', 'carrying', 'extra']

    d = {}

    for label in labels:
        d[label] = []


    with open(csv_filename) as csv_fd:
        reader = csv.reader(csv_fd, delimiter=';')
        next(reader)  # пропускаем заголовок

        for row in reader:
            for i in range(len(labels)):
                element = row[i] if i < len(row) else ''
                d[labels[i]].append(element)

    return d


def valid_image_ext(image_path):
    valid_image_ext = ['.jpg', '.jpeg', '.png', '.gif']
    image_ext = os.path.splitext(image_path)

    if len(image_ext) != 2 or not image_ext[1] in valid_image_ext:
        return False

    return True

def valid_row(d, i):
    attrs = [d['brand'][i], d['photo_file_name'][i], d['carrying'][i]]

    for attr in attrs:
        if attr == '':
            return False

    valid_types = ['car', 'truck', 'spec_machine']

    return (valid_image_ext(d['photo_file_name'][i]) and
            d['car_type'][i] in valid_types)


def get_car_list(csv_filename):
    d = get_dict_from_csv(csv_filename)
    car_list = []

    for i in range(len(d['car_type'])):
        if not valid_row(d, i):
            continue

        base_attrs = [d['brand'][i], d['photo_file_name'][i], d['carrying'][i]]

        try:
            if d['car_type'][i] == 'car':
                if d['passenger_seats_count'][i] == '':
                    raise ValueError
                car = Car(*base_attrs, d['passenger_seats_count'][i])

            elif d['car_type'][i] == 'truck':
                car = Truck(*base_attrs, d['body_whl'][i])

            elif d['car_type'][i] == 'spec_machine':
                if d['extra'][i] == '':
                    raise ValueError

                car = SpecMachine(*base_attrs, d['extra'][i])

        except ValueError:
            pass
        else:
            car_list.append(car)

    return car_list
