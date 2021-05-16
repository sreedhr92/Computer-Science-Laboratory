rem *******************************************************************
rem altering table constraints

alter table artist
add(gender varchar2(10));

alter table studio 
add(constraint phone_un unique(phone));

alter table sungby
modify(recording_date date constraint date_null not null);

alter table song
modify(song_genre varchar2(20) constraint add_song_check check(song_genre in ('PHI','REL','LOV','DEV','PAT','NAT')));

alter table sungby
drop constraint alb_trackno_pk;

alter table sungby
add constraint alb_trackno_pk foreign key(album__ID,track__no) references song(album__id,track_no) on delete cascade;


rem adding values to artist table with gender
insert into artist values
(
	106,
	'Lil pump',
	'male'
);

insert into artist values
(
	107,
	'Katy perry',
	'female'
);


rem violating the phone number to be unique
insert into studio values
(
	'T-series',
	'India',
	9876543212
);


rem violating the recording date to be not null
insert into sungby values
(
	12,
	106,
	7,
	null
);

insert into song values
(
	12,
	9,
	'fake love',
	8,
	'NAT'
);

