import { Injectable } from '@nestjs/common';
import { InjectRepository } from '@nestjs/typeorm';
import { Repository } from 'typeorm';
import { Pessoa } from './pessoa.entity';
import { CreatePessoaDto } from './create-pessoa.dto';

@Injectable()
export class PessoaService {
  constructor(
    @InjectRepository(Pessoa)
    private pessoaRepository: Repository<Pessoa>,
  ) {}

  create(createPessoaDto: CreatePessoaDto) {
    return this.pessoaRepository.save(createPessoaDto);
  }

  findAll() {
    return this.pessoaRepository.find();
  }

  findOne(id: number) {
    return this.pessoaRepository.findOneBy({ id: id });
  }

  remove(id: number) {
    return this.pessoaRepository.delete(id);
  }
}